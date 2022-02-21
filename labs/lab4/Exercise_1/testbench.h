#ifndef TESTBENCH_H
#define TESTBENCH_H

SC_MODULE(Testbench)
{
	//public:
	sc_out<bool> car;
	sc_in<color> Main_road, Secondary_road;
	
	SC_CTOR(Testbench)
	//: car("car"), Main_road("Main"), Secondary_road("Secondary")
	{
		SC_THREAD(INPUT_GEN);
		
		SC_METHOD(OUTPUT_CHECK);
		sensitive << Main_road << Secondary_road;
		
		SC_METHOD(CAR_CHECK);
		sensitive << car;

		SC_THREAD(MONITOR_1);
		SC_THREAD(MONITOR_2);
		SC_THREAD(MONITOR_3);
	}
	
	void INPUT_GEN() {
		car.write(false);
		wait(5, SC_SEC);
		car.write(true);
		wait(1, SC_SEC);		// Do not wait for green light
		car.write(false);
		wait(30, SC_SEC);
		car.write(true);
		while (Secondary_road.read() != GREEN)
			wait(1, SC_SEC);
		car.write(false);
		wait(30, SC_SEC);
		sc_stop();
	}
	
	void OUTPUT_CHECK() {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		cout << "@" << sc_time_stamp() << " Main      road " << table[Main_road.read()] << std::endl;
		cout << "@" << sc_time_stamp() << " Secondary road " << table[Secondary_road.read()] << std::endl;
		cout << std::endl;
	}
	
	void CAR_CHECK() { 
		cout << "@" << sc_time_stamp() << " car " << (car ? "arrives" : "leaves") << std::endl;
		cout << std::endl;
	}

	/* Check if when one traffic light is green the other is red */

	void MONITOR_1() {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		while(1) {
			wait(Main_road.value_changed_event() | Secondary_road.value_changed_event());
			if (strcmp(table[Main_road.read()],"GREEN")==0) {
				if (strcmp(table[Secondary_road.read()],"RED")!=0) {
					cout << "@" << sc_time_stamp() << " Main      road " << table[Main_road.read()] << " and Secondary road " << table[Secondary_road.read()] << endl;
					cout << std::endl;
				}
			} else if (strcmp(table[Secondary_road.read()],"GREEN")==0) {
				if (strcmp(table[Main_road.read()],"RED")!=0) {
					cout << "@" << sc_time_stamp() << " Main      road " << table[Main_road.read()] << " and Secondary road " << table[Secondary_road.read()] << endl;
					cout << std::endl;
				}
			}
		}
	}
	
	/* Check if the minimum duration of any green light is 10 seconds */
	
	void MONITOR_2() {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		wait(SC_ZERO_TIME);
		while(1) {	
			wait(Main_road.value_changed_event() | Secondary_road.value_changed_event());
			if (strcmp(table[Main_road.read()],"GREEN")==0) {
				wait(10, SC_SEC);
				if (strcmp(table[Main_road.read()],"GREEN")!=0) {
					cout << "@" << sc_time_stamp() << " Main      road GREEN for less than 10 seconds" << endl;
					cout << std::endl;
				}
			} else if (strcmp(table[Secondary_road.read()],"GREEN")==0) {
				wait(10, SC_SEC);
				if (strcmp(table[Secondary_road.read()],"GREEN")!=0) {
					cout << "@" << sc_time_stamp() << " Secondary road GREEN for less than 10 seconds" << endl;
					cout << std::endl;
				}
			}
		}
	}
	
	/* Check if the maximum duration of any yellow light is 5 seconds */
	
	void MONITOR_3() {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		wait(SC_ZERO_TIME);
		while(1) {	
			wait(Main_road.value_changed_event() | Secondary_road.value_changed_event());
			if (strcmp(table[Main_road.read()],"YELLOW")==0) {
				wait(5, SC_SEC);
				wait(1, SC_US);
				//wait(SC_ZERO_TIME);
				if (strcmp(table[Main_road.read()],"YELLOW")==0) {
					cout << "@" << sc_time_stamp() << " Main      road YELLOW for more than 5 seconds" << endl;
					cout << std::endl;
				}
			} else if (strcmp(table[Secondary_road.read()],"YELLOW")==0) {
				wait(5, SC_SEC);
				wait(1, SC_US);
				//wait(SC_ZERO_TIME);
				if (strcmp(table[Secondary_road.read()],"YELLOW")==0) {
					cout << "@" << sc_time_stamp() << " Secondary road YELLOW for more than 5 seconds" << endl;
					cout << std::endl;
				}
			}
		}
	}

};

#endif
