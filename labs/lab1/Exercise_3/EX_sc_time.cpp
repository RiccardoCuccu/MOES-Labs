#include "EX_sc_time.h"

void EX_sc_time::time_thread(void) {
	cout << "INFO: Time resolution is " << sc_get_time_resolution() << endl;
	
	sc_time t(20, SC_NS);

	for (int i=20; i>0; i--) {
		wait(t);
		cout << "Elapsed time is " << sc_time_stamp() << ", countdown value is " << i << endl;
	}

	cout << "End" << endl;
}
