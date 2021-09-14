#include "systemc.h"
using std::cout;
using std::endl;
#include "EX_sc_time.h"
using namespace sc_core;

int sc_main(int argc, char* argv[]) {
	sc_set_time_resolution(1,SC_FS);
	//sc_set_default_time_unit(1,SC_SEC);  //deprecated
	
	EX_sc_time time_inst("time_inst");
	
	sc_start();

	return 0;
}
