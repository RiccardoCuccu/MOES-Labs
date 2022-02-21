#include <systemc.h>

SC_MODULE(TIMER) {

	sc_in<bool> start;
	sc_out<bool> sec_5;

	SC_CTOR(TIMER) {
		SC_THREAD(CLOCK_GEN);
		sensitive << start;
	}

	void CLOCK_GEN() {
		sec_5.write(false);
		while(1) {
			wait();					// wait for the start signal to change
			wait(5, SC_SEC);
			sec_5.write(true);
			wait(SC_ZERO_TIME);
			sec_5.write(false);
		}
	}
};
