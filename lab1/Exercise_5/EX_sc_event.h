#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(EX_sc_event) {

	sc_event	evt_wakeup_tic, evt_wakeup_toc;		// declaration of sc_event variables
	
	SC_CTOR(EX_sc_event) {
		SC_THREAD(tic_thread);
		SC_THREAD(toc_thread);
	}

	void tic_thread(void);
	void toc_thread(void);
};
