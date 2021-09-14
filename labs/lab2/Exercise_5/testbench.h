#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(TestBench) {
	sc_in<int>	C_out;			// declare an input port
	sc_in<int>	Sum;			// declare an input port
	sc_out<int>	A;			// declare an output port
	sc_out<int>	B;			// declare an output port
	sc_out<int>	C;			// declare an output port

	SC_CTOR(TestBench) {
		SC_THREAD(gen_thread);

		SC_METHOD(react_method);
		sensitive << C_out << Sum;
	}

	void gen_thread(void);
	void react_method(void);
};
