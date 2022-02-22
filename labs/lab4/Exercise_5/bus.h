#ifndef BUS_H
#define BUS_H

#include "defines.h"

SC_MODULE(BUS), virtual public bus_if {
	sc_port<bus_if> timer;

	SC_CTOR(BUS): timer("timer") {}

	virtual void write(sc_uint<32> addr, sc_uint<32> data) {
		switch(addr){
		case TIMER_COUNTER_ADDR:
			timer->write(0, data);
			break;
		case TIMER_MAX_VALUE_ADDR:
			timer->write(1, data);
			break;
		case TIMER_CONTROL_ADDR:
			timer->write(2, data);
			break;
		default:
			SC_REPORT_ERROR(name(), "write address not correct");
			break;
		}
	}
	
	virtual sc_uint<32> read(sc_uint<32> addr) {
		sc_uint<32> result=0;
		switch(addr) {
		case TIMER_COUNTER_ADDR:
			result=timer->read(0);
			break;
		case TIMER_MAX_VALUE_ADDR:
			result=timer->read(1);
			break;
		case TIMER_CONTROL_ADDR:
			result=timer->read(2);
			break;
		default:
			SC_REPORT_ERROR(name(), "read address not correct");
			break;
		}
		return result;
	}
};

#endif
