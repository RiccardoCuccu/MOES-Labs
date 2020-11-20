#include "adder.h"

void Adder::proc_method(void) {
	int a = A->read();				// read input A
	int b = B->read();				// read input B
	int c = C->read();				// read input C

	int sum = a ^ b ^ c;
	int c_out = (a & b) ^ (c & (a ^ b));

	cout << std::string(50,'=') << endl;
	cout << "Adder object '" << name() << "' receives @ " << sc_time_stamp() << endl;
	cout << std::string(50,'-') << endl;
	cout << "- A: " << a << endl;
	cout << "- B: " << b << endl;
	cout << "- C: " << c << endl;
	cout << "Then" << endl;
	cout << "- C_out: " << c_out << endl;
	cout << "- Sum: " << sum << endl;

	Sum->write(sum);				// write output Sum
	C_out->write(c_out);				// write output C_out
}
