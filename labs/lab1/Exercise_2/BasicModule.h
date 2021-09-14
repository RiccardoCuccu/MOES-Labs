#include "systemc.h"

SC_MODULE(BasicModule) {	// declare SystemC module "BasicModule"

	/* constructor */
	SC_CTOR(BasicModule) {	// note: constructor argument should be the same with the module name

		SC_THREAD(ex_thread_process);	// register a simulation process to the simulation kernel
	}

	void ex_thread_process(void);	// declaration of simulationn process 
};

