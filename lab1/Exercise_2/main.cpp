#include "systemc.h"
#include "BasicModule.h"

int sc_main(int argc, char* argv[]) {
	/* elaboration stage */
	BasicModule my_instance("my_instance");	// instantiate BasicModule with a name value "my_instance"

	/* simulation stage */
	sc_start();

	return 0;
}
