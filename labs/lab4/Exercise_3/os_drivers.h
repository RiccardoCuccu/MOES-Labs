#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

SC_MODULE(OS_DRIVERS), public car_if, public light_if, public timer_if {

	SC_CTOR(OS_DRIVERS) {}

	virtual void wait_for_sec(unsigned int s) {
		printf ("Wait for %d sec\n", s);
		wait(s, SC_SEC);
	}

	virtual void set_main(color c) {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		printf("@%s M: %s\n", sc_time_stamp().to_string().c_str(), table[c]);
	}

	virtual void set_sec(color c) {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		printf("@%s S: %s\n", sc_time_stamp().to_string().c_str(), table[c]);
	}

	virtual void wait_for_car() {
		printf("Wait for car\n");
		wait(30, SC_SEC);
	}
};

#endif
