#include "systemc.h"
#include "EX_sc_event.h"

int sc_main(int argc, char * argv[]) {
	
	EX_sc_event inst("instance");

	sc_start();

	return 0;
}
