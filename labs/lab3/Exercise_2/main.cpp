#include "systemc.h"
//#include "tlc.h"
#include "testbench.h"

int sc_main(int argc, char *argv[]) {

	sc_signal<bool> sig_car;
	sc_signal<color> sig_main_tl, sig_side_tl;

	TLC TLC_inst("TLC_inst");
	TestBench TestBench_inst("TestBench_inst");

	TLC_inst.car(sig_car);
	TLC_inst.main_tl(sig_main_tl);
	TLC_inst.side_tl(sig_side_tl);

	TestBench_inst.car(sig_car);
	TestBench_inst.main_tl(sig_main_tl);
	TestBench_inst.side_tl(sig_side_tl);

	sc_start();

	return 0;
}
