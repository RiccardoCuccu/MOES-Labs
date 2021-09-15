#include "EX_tictoc.h"
#define DELAY 10
#define BOUNCES 15

void EX_tictoc::tic_thread(void) {
	int counter = 0;

	while (counter < BOUNCES) {
		if (counter == 0) wait(DELAY, SC_NS);
		else wait(evt_wakeup_tic);

		cout << "TIC @ " << sc_time_stamp() << endl;
		//cout << "TIC" << endl;
		evt_wakeup_toc.notify(DELAY, SC_NS);
		counter++;
	}

	wait(DELAY, SC_NS);
	cout << "TIC has been activated " << counter << " times" << endl;
}

void EX_tictoc::toc_thread(void) {
	int counter = 0;
	while (counter < BOUNCES) {
		wait(evt_wakeup_toc);

		cout << "TOC @ " << sc_time_stamp() << endl;
		//cout << "TOC" << endl;
		evt_wakeup_tic.notify(DELAY, SC_NS);
		counter++;
	}

	wait(DELAY, SC_NS);
	cout << "TOC has been activated " << counter << " times" << endl;
}
