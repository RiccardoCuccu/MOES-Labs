#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Adder) {
	sc_in<int>	A;			// declare an input port
	sc_in<int>	B;			// declare an input port
	sc_in<int>	C;			// declare an input port
	sc_out<int>	C_out;			// declare an output port
	sc_out<int>	Sum;			// declare an output port

	SC_CTOR(Adder) {
		SC_METHOD(proc_method);
		sensitive << A << B << C;
	}
 
	void proc_method(void);
};
