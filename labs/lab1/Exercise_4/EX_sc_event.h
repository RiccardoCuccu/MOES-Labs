#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(EX_sc_event) {

	sc_event	evt1, evt2;		// declaration of sc_event variables
	
	SC_CTOR(EX_sc_event) {
		SC_THREAD(proc1_thread);
		SC_THREAD(proc2_thread);
	}

	void proc1_thread(void);
	void proc2_thread(void);
};
