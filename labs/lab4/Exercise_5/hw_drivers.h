#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H


SC_MODULE(HW_DRIVERS), public car_if, public light_if {
	
	sc_in<bool> car;
	sc_out<color> M, S;

	SC_CTOR(HW_DRIVERS) {}

	virtual void set_main(color c) {
		M.write(c);
	}

	virtual void set_sec(color c) {
		S.write(c);
	}

	virtual void wait_for_car() {
		while(car.read()==false) wait(car.posedge_event());
	}
};

#endif
