#include <iostream>	// include the header file for input and output stream
#include "systemc.h"	// all systemc modules should include systemc.h header file
using std::cout;	// introduce the standard output stream object "cout" to the current scope
using std::endl;	// introduce the standard newline object "endl" to the current scope

SC_MODULE(HelloWorld) {	// declare a new SystemC module "HelloWorld"
	
	SC_CTOR(HelloWorld) {	// constructor
		// nothing in the constructor
	}

	void say_hello(void);	// declare a member function
};
