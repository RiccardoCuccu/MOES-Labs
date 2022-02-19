#include <systemc.h>

enum color {
	GREEN, YELLOW, RED
};

SC_MODULE(TLC) {

	sc_in<bool> car;
	sc_out<color> main_tl, side_tl;

	SC_CTOR(TLC) {
		SC_THREAD(proc_thread);
		sensitive << car;
	}

	void proc_thread(void);
};
