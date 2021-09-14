#include "testbench.h"

void TestBench::gen_thread(void) {
	int cnt = 10;						// counter
	int a, b, c;						// inputs
	uint16_t lfsr = 0xACE1u;				// LFSR seed
	uint16_t bit;						// last bit

	while(cnt--) {
		wait(10, SC_NS);

		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5));
 		lfsr = (lfsr >> 1) | (bit << 15);
 		a = (lfsr & 0x0001);				// first bit
 		b = (lfsr & 0x0002) >> 1;			// second bit
 		c = (lfsr & 0x0004) >> 2;			// third bit

 		A->write(a);					// write output A
 		B->write(b);					// write output B
 		C->write(c);					// write output C

 		cout << std::string(50,'=') << endl;
		cout << "TestBench object '" << name() << "' sends @ " << sc_time_stamp() << endl;
		cout << std::string(50,'-') << endl;
		cout << "- A: " << a << endl;
		cout << "- B: " << b << endl;
		cout << "- C: " << c << endl;
	}
}

void TestBench::react_method(void) {
	int a = A->read();
	int b = B->read();
	int c = C->read();

	int sum = Sum->read();					// read input Sum
	int c_out = C_out->read();				// read input C_out

	int sum_test = a ^ b ^ c;
	int c_out_test = (a & b) ^ (c & (a ^ b));

	cout << std::string(50,'=') << endl;
	cout << "TestBench object '" << name() << "' receives @ " << sc_time_stamp() << endl;
	cout << std::string(50,'-') << endl;
	cout << "C_out of Adder is " << c_out << " and C_out of TestBench is " << c_out_test << endl;
	cout << "Sum of Adder is " << sum << " and Sum of TestBench is " << sum_test << endl;
	if (sum == sum_test || c_out == c_out_test)
	{
		cout << "*** All right! ***" << endl;
	}
	else
	{
		cout << "*** Something wrong! ***" << endl;
	}
}
