#include "EX_sc_time.h"

int sc_main(int argc, char *argv[]) {
	sc_set_time_resolution(1,SC_FS);
	
	EX_sc_time time_inst("time_inst");
	
	sc_start();

	return 0;
}
