#include "EX_sc_time.h"

void EX_sc_time::time_thread(void) {
	cout << "INFO: Time resolution is " << sc_get_time_resolution() << endl;
	const sc_time t_20NS(20,SC_NS);

	sc_time t_DELAY(t_20NS);

	for (int i=20; i>0; i--) {
		wait(t_DELAY);
		cout << i << " => " << sc_time_stamp() << endl;
	}

	cout << "End" << endl;

}
