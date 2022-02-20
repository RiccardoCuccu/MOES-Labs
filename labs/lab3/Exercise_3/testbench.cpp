#include "testbench.h"

const char * TABLE[] = { "GREEN", "YELLOW", "RED" } ;

void TestBench::proc_driver(void) {
	int i = 10;
	uint16_t lfsr = 0xACE1u;			// LFSR seed
	uint16_t S;					// seconds of waiting

	car.write(0);

	while (i--) {
		S = (lfsr & 0x000F) | 0x0001;		// generates a random number from 1 to 15
		lfsr = (lfsr >> 1) | ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) << 15;
		wait(S, SC_SEC);
		car.write(!car.read());
	}

	sc_stop();
}

/* Check if when one traffic light is green the other is red */

void TestBench::proc_monitor1(void) {
	while(1) {	
		wait(main_tl.value_changed_event() | side_tl.value_changed_event());
		if (strcmp(TABLE[main_tl.read()],"GREEN")==0) {
			if (strcmp(TABLE[side_tl.read()],"RED")!=0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Main traffic light is " << TABLE[main_tl.read()] << " and side traffic light is " << TABLE[side_tl.read()] << endl;
			}
		} else if (strcmp(TABLE[side_tl.read()],"GREEN")==0) {
			if (strcmp(TABLE[main_tl.read()],"RED")!=0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Main traffic light is " << TABLE[main_tl.read()] << " and side traffic light is " << TABLE[side_tl.read()] << endl;
			}
		}
	}
}

/* Check if the minimum duration of any green light is 10 seconds */

void TestBench::proc_monitor2(void) {
	wait(SC_ZERO_TIME);
	while(1) {	
		wait(main_tl.value_changed_event() | side_tl.value_changed_event());
		if (strcmp(TABLE[main_tl.read()],"GREEN")==0) {
			wait(10, SC_SEC);
			if (strcmp(TABLE[main_tl.read()],"GREEN")!=0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Main traffic light was GREEN for less than 10 seconds" << endl;
			}
		} else if (strcmp(TABLE[side_tl.read()],"GREEN")==0) {
			wait(10, SC_SEC);
			if (strcmp(TABLE[side_tl.read()],"GREEN")!=0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Side traffic light was GREEN for less than 10 seconds" << endl;
			}
		}
	}
}

/* Check if the maximum duration of any yellow light is 5 seconds */

void TestBench::proc_monitor3(void) {
	wait(SC_ZERO_TIME);
	while(1) {	
		wait(main_tl.value_changed_event() | side_tl.value_changed_event());
		if (strcmp(TABLE[main_tl.read()],"YELLOW")==0) {
			wait(5, SC_SEC);
			wait(SC_ZERO_TIME);
			if (strcmp(TABLE[main_tl.read()],"YELLOW")==0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Main traffic light was YELLOW for more than 5 seconds" << endl;
			}
		} else if (strcmp(TABLE[side_tl.read()],"YELLOW")==0) {
			wait(5, SC_SEC);
			wait(SC_ZERO_TIME);
			if (strcmp(TABLE[side_tl.read()],"YELLOW")==0) {
				cout << "ERROR @ " << sc_time_stamp() << ": Side traffic light was YELLOW for more than 5 seconds" << endl;
			}
		}
	}
}
