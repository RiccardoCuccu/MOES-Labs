#include <systemc.h>
#include "tlc.h"

SC_MODULE(TestBench) {

	sc_out<bool> car;
	sc_in<color> main_tl, side_tl;

	SC_CTOR(TestBench) {
		SC_THREAD(proc_driver);
		SC_THREAD(proc_monitor1);
		SC_THREAD(proc_monitor2);
		SC_THREAD(proc_monitor3);
	}

	void proc_driver(void);
	void proc_monitor1(void);
	void proc_monitor2(void);
	void proc_monitor3(void);
};
