#ifndef TIMER_PERIPHERAL_H
#define TIMER_PERIPHERAL_H

// This must implement the bus interface for the timer functionality

SC_MODULE(TIMER_PERIPHERAL), virtual public bus_if {
	//sc_signal<sc_uint<32>> counter, max_value, control;
	sc_uint<32> counter, max_value, control;
	sc_event start;
	sc_in<bool> clk;

	SC_CTOR(TIMER_PERIPHERAL) {
		SC_THREAD(count);
		sensitive << clk.pos();
	}

	virtual void reset() {
		counter=0;
		control=0;
		max_value=0;
	}

	virtual void write(sc_uint<32> addr, sc_uint<32> data) {
		switch(addr) {
			case 0:
				counter=data;
				start.notify(SC_ZERO_TIME);
				break;
			case 1:
				max_value=data;
				break;
			case 2:
				control=data;
				break;
			default:
				SC_REPORT_ERROR(name(), "write address not correct");
				break;
		}
	}

	virtual sc_uint<32> read(sc_uint<32> addr) {
		sc_uint<32> result;
		switch(addr) {
			case 0:
				result=counter;
				break;
			case 1:
				result=max_value;
				break;
			case 2:
				result=control;
				break;
			default:
				SC_REPORT_ERROR(name(), "read address not correct");
				break;
		}
		return result;
	}

	void count() {
		counter=0;
		control=0;
		max_value=0;
		wait(start);
		while(1) {
			wait();					// for clk.pos()
			if(counter >= max_value) {
				control[2]=true;
				counter=0;
				wait();				// for clk.pos()
				if(!control[1]) {		// if not continuous, wait
					wait(start);
				}
				control[2]=false;		// running again
			}
			counter++;
		}
	}
};

#endif
