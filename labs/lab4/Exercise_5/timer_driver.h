#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

#include "defines.h"

SC_MODULE(TIMER_DRIVER), virtual public timer_if {
	sc_port<bus_if> bus;						// connected toward the bus

	SC_CTOR(TIMER_DRIVER): bus("bus") { }

	virtual void reset() { }

	virtual void wait_for_sec(unsigned int sec) {
		bus->write(TIMER_MAX_VALUE_ADDR, sec * 1000000); 	// set period
		bus->write(TIMER_CONTROL_ADDR, 0);			// one shot mode
		bus->write(TIMER_COUNTER_ADDR, 0);			// restart timer
		while(!(bus->read(TIMER_CONTROL_ADDR) [2]))
			wait(1, SC_MS);					// wait until done
		}
};

#endif
