#include "EX_sc_event.h"

void EX_sc_event::proc1_thread(void) {
	wait(20, SC_NS);	// active after 20ns

	cout << "proc1 notifies evt2 to start proc2 @ " << sc_time_stamp() << " : notify(void)" << endl;
	evt2.notify(SC_ZERO_TIME);
	wait(20, SC_NS);	// sleep for 20ns

	cout << "proc1 notifies evt2 to start proc2 @ " << sc_time_stamp() << " : notify(SC_ZERO_TIME)" << endl;
	evt2.notify(SC_ZERO_TIME);
	wait(20, SC_NS);	// sleep for 20ns

	cout << "proc1 notifies evt2 to start proc2 @ " << sc_time_stamp() << " : notify(sc_time)" << endl;
	sc_time t(10, SC_NS);	// define a sc_time variable
	evt2.notify(t);
	wait(20, SC_NS);	// sleep for 20ns

	cout << "proc1 notifies evt2 to start proc2 @ " << sc_time_stamp() << " : notify(double, time_unit)" << endl;
	evt2.notify(15, SC_NS);
	wait(20, SC_NS);	// sleep for 20ns

	wait(evt1);
	cout << "proc1 received evt1's notification from proc2 @ " << sc_time_stamp() << endl; 

}

void EX_sc_event::proc2_thread(void) {
	wait(evt2);		// 1st active when evt2 notified
	cout << "1st active, proc2 received evt2's notification from proc1 @ " << sc_time_stamp() << endl;

	wait(evt2);		// 2nd active when evt2 notified
	cout << "2nd active, proc2 received evt2's notification from proc1 @ " << sc_time_stamp() << endl;

	wait(evt2);		// 3rd active when evt2 notified
	cout << "3rd active, proc2 received evt2's notification from proc1 @ " << sc_time_stamp() << endl;

	wait(evt2);		// 4th active when evt2 notified
	cout << "4th active, proc2 received evt2's notification from proc1 @ " << sc_time_stamp() << endl;

	wait(30, SC_NS);
	evt1.notify(SC_ZERO_TIME);	// active proc1

}
