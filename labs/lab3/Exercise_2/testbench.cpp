#include "testbench.h"

/*void TestBench::proc_bad_driver(void) {
	car.write(0);

	wait(5, SC_SEC);
	car.write(1);

	wait(1, SC_SEC);
	car.write(0);

	wait(30, SC_SEC);
	car.write(1);

	wait(1, SC_SEC);
	car.write(0);

	wait(20, SC_SEC);

	sc_stop();
}*/


void TestBench::proc_good_driver(void) {
	car.write(0);

	wait(5, SC_SEC);
	car.write(1);

	while(main_tl.read() != 2) wait(main_tl.value_changed_event());
	car.write(0);

	wait(30, SC_SEC);
	car.write(1);

	while(main_tl.read() != 2) wait(main_tl.value_changed_event());
	car.write(0);

	wait(20, SC_SEC);

	sc_stop();
}

void TestBench::proc_output_check(void) {
	const char * TABLE[] = { "GREEN", "YELLOW", "RED" } ;
	if(car.event()) {
		cout << "Car status is " << car.read() << " @ " << sc_time_stamp() << endl;
	}
	if(main_tl.event()) {
		cout << TABLE[main_tl.read()] << " on main traffic light @ " << sc_time_stamp() << endl;
	}
	if(side_tl.event()) {
		cout << TABLE[side_tl.read()] << " on side traffic light @ " << sc_time_stamp() << endl;
	}
}

