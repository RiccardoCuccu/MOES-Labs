#include <systemc.h>

SC_MODULE(TIMER_CLK) {

	sc_in<bool> start;
	sc_in<bool> clk;
	sc_out<bool> sec_5;

	SC_CTOR(TIMER_CLK) {
		SC_THREAD(CLOCK_GEN);
		sensitive << start << clk.pos();
	}

	void CLOCK_GEN() {
		int i;
		sec_5.write(false);
		while(1) {
			i = 5000000;
			wait(start.default_event());		// wait for the start signal to change
			while(i) {
				i--;
				wait(clk.posedge_event());
			}
			sec_5.write(true);
			wait(SC_ZERO_TIME);
			sec_5.write(false);
		}
	}
};
