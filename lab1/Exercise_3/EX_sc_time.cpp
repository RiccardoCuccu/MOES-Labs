#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
#include <string>
#include "EX_sc_time.h"

void EX_sc_time::time_thread(void) {
	//cout << "INFO: Time resolution is " << sc_get_time_resolution() << endl;
	const sc_time t_20NS(20,SC_NS);

	sc_time t_DELAY(t_20NS);

	for (int i=20; i>0; i--) {
		wait(t_DELAY);
		//std::cout << i << "\t=>\t" << sc_time_stamp() << std::endl;
		std::cout << i << std::endl;
	}

	//cout << "End" << endl;

} //end time_thread()
