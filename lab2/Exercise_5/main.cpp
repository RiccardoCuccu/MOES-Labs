#include "systemc.h"
#include "adder.h"
#include "testbench.h"

int sc_main(int argc, char * argv[]) {
	sc_signal<int>	sig_A;			// define a channel
	sc_signal<int>	sig_B;
	sc_signal<int>	sig_C;
	sc_signal<int>	sig_C_out;
	sc_signal<int>	sig_Sum;

	Adder		Adder_inst("AdderObj");
	TestBench	TestBench_inst("TestBenchObj");

	Adder_inst.A(sig_A);			// connect Adder_inst's input port "A" to sig_A
	Adder_inst.B(sig_B);			// connect Adder_inst's input port "B" to sig_B
	Adder_inst.C(sig_C);			// connect Adder_inst's input port "C" to sig_C
	Adder_inst.C_out(sig_C_out);		// connect Adder_inst's output port "C_out" to sig_C_out
	Adder_inst.Sum(sig_Sum);		// connect Adder_inst's output port "Sum" to sig_Sum

	TestBench_inst.A(sig_A);		// connect TestBench_inst's output port "A" to sig_A
	TestBench_inst.B(sig_B);		// connect TestBench_inst's output port "B" to sig_B
	TestBench_inst.C(sig_C);		// connect TestBench_inst's output port "C" to sig_C
	TestBench_inst.C_out(sig_C_out);	// connect TestBench_inst's input port "C_out" to sig_C_out
	TestBench_inst.Sum(sig_Sum);		// connect TestBench_inst's input port "Sum" to sig_Sum

	sc_start();

	return 0;
}

