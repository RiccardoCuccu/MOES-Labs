#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

// Here you must implement a module that implements all three interfaces

SC_MODULE(OS_DRIVERS), public car_if, public light_if, public timer_if {
	
	sc_in<bool> car;
	sc_out<color> M, S;

	SC_CTOR(OS_DRIVERS) {}

	virtual void wait_for_sec(unsigned int s) {
		printf ("Wait for %d sec\n", s);
		wait(s, SC_SEC); 			// to inform simulator
	}

	virtual void set_main(color c) {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		printf("@%s M: %s\n", sc_time_stamp().to_string().c_str(), table[c]);
		M.write(c);
	}

	virtual void set_sec(color c) {
		static const char *table[]= {"RED","YELLOW","GREEN"};
		printf("@%s S: %s\n", sc_time_stamp().to_string().c_str(), table[c]);
		S.write(c);
	}

	virtual void wait_for_car() {
		printf("Wait for car\n");
		wait(30, SC_SEC);
	}
};

#endif
