#include "BasicModule.h"

void BasicModule::ex_thread_process(void) {	// implementation of member function (process)
	// display an output that could count down from 3 to 1
	for (int i=3; i>0; i--) {
		std::cout << i << std::endl;
	}
}

