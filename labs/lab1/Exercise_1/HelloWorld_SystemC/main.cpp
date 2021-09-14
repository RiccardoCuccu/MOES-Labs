#include "systemc.h"	// all systemc modules should include systemc.h header file
#include "HelloWorld.h"	// include the module (class) declaration file

int sc_main(int argc, char * argv[]) {			// main function

	HelloWorld HelloWorld_inst("HelloWorld");	// instantiate module (class) object HelloWorld_inst with a string "HelloWorld" as the input value

	HelloWorld_inst.say_hello();			// call the member function of HelloWorld_inst

	return 0;					// return
}
