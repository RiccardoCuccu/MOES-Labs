// If you prefer using printf, you can instead 
// #include <stdio.h>
#include <iostream>	// include the header file for input and output stream

using std::cout;	// introduce the standard output stream object "cout" to the current scope
using std::endl;	// introduce the standard newline object "endl" to the current scope

class HelloWorld {	// declare a new class "HelloWorld"

	public:		// access level
		HelloWorld(){}		// constructor

		void say_hello(void);	// declare a member function
};
