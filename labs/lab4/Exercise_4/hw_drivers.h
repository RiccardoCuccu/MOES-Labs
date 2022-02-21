#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

SC_MODULE(HW_DRIVERS), public car_if, public light_if, public timer_if {
	
	sc_in<bool> car;
	sc_in<bool> clk;
	sc_out<color> M, S;

	SC_CTOR(HW_DRIVERS) {}

	virtual void wait_for_sec(unsigned int s) {
		int i = s*1000000;
		while(i--) {
			wait(clk.posedge_event());
		}
	}

	virtual void set_main(color c) {
		M.write(c);
	}

	virtual void set_sec(color c) {
		S.write(c);
	}

	virtual void wait_for_car() {
		while(car.read()==false) wait(car.posedge_event());
	}
};

#endif
