#include "EX_tictoc.h"
#define DELAY 10
#define BOUNCES 15

sc_time t(DELAY, SC_NS);

void EX_tictoc::tic_thread(void) {
	int counter = 0;

	while (counter < BOUNCES) {
		if (counter == 0) wait(t);
		else wait(evt_wakeup_tic);

		cout << "TIC @ " << sc_time_stamp() << endl;
		evt_wakeup_toc.notify(t);
		counter++;
	}

	wait(t);
	cout << "TIC has been activated " << counter << " times" << endl;
}

void EX_tictoc::toc_thread(void) {
	int counter = 0;

	while (counter < BOUNCES) {
		wait(evt_wakeup_toc);

		cout << "TOC @ " << sc_time_stamp() << endl;
		evt_wakeup_tic.notify(t);
		counter++;
	}

	wait(t);
	cout << "TOC has been activated " << counter << " times" << endl;
}
