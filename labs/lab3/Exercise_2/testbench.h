#include <systemc.h>
#include "tlc.h"

SC_MODULE(TestBench) {

	sc_out<bool> car;
	sc_in<color> main_tl, side_tl;

	SC_CTOR(TestBench) {
		//SC_THREAD(proc_bad_driver);
		SC_THREAD(proc_good_driver);
		SC_METHOD(proc_output_check);
			sensitive << car << main_tl << side_tl;
	}

	//void proc_bad_driver(void);
	void proc_good_driver(void);
	void proc_output_check(void);
};
