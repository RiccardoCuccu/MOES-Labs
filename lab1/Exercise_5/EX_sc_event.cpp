#include "EX_sc_event.h"

void EX_sc_event::tic_thread(void) {
	int counter = 0;
	wait(10, SC_NS);
	//cout << "TIC " << sc_time_stamp() << endl;
	cout << "TIC" << endl;
	evt_wakeup_toc.notify(10, SC_NS);

	while (counter < 10) {
		wait(evt_wakeup_tic);
		//cout << "TIC " << sc_time_stamp() << endl;
		cout << "TIC" << endl;
		evt_wakeup_toc.notify(10, SC_NS);
		counter++;
	}

	wait(10, SC_NS);
	cout << "TIC has been activated " << counter << " times" << endl;
}

void EX_sc_event::toc_thread(void) {
	int counter = 0;
	while (counter < 10) {
		wait(evt_wakeup_toc);
		//cout << "TOC " << sc_time_stamp() << endl;
		cout << "TOC" << endl;
		evt_wakeup_tic.notify(10, SC_NS);
		counter++;
	}

	wait(10, SC_NS);
	cout << "TOC has been activated " << counter << " times" << endl;
}
