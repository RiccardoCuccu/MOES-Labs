#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <systemc>
using namespace sc_dt; 

int sc_main(int argc, char *argv[]) {

	/* ================================================================================== */
	/* logic and logic vector */
	sc_logic buf(sc_dt::Log_Z);		// define a logic bit with an assigned value Log_Z (high impedence)
	sc_lv<8> data_drive("zz01XZ1Z");	// define a logic vector with width of 8 and assigned value of zz01XZ1Z
	data_drive.range(5,4) = "ZZ";		// range selection, final result is ZZZZXZ1Z
	buf = '1';
	buf = SC_LOGIC_1;
	cout << "INFO:        buf is '" << buf << "'" << endl;
	cout << "INFO: data_drive is '" << data_drive << "'" << endl;

	/* ================================================================================== */
	/* logic operation */
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);
	sc_bit flag(SC_LOGIC_1);		// more efficient to use bool
	sc_bv<5> positions = "01101";
	sc_bv<6> mask = "100111";
	sc_bv<5> active = positions & mask;	// 00101
	sc_bv<1> all = active.and_reduce();	// SC_LOGIC_0
	
	positions.range(3,2) = "00";		// 00001
	positions[2] = active[0] ^ flag;	// XOR
	cout << "INFO:  positions is '" << positions << "'" << endl;
	cout << "INFO:       mask is '" << mask      << "'" << endl;
	cout << "INFO:     active is '" << active    << "'" << endl;
	cout << "INFO:       flag is '" << flag      << "'" << endl;
	cout << "INFO:        all is '" << all       << "'" << endl;


	/* ================================================================================== */
	/* native C++ data types */
	cout << std::string(40,'-') << endl;
	cout << "INFO: Adding 3 shorts to produce an int" << endl;
	short a = 32767;
	short b = 32767;
	short c = 32767;
	cout << "INFO: short a = " << a << endl;
	cout << "INFO: short b = " << b << endl;
	cout << "INFO: short c = " << c << endl;
	cout << "INFO: a + b + c = " << a + b + c << " OK" << endl;
	short ssum = a + b + c;
	cout << "INFO: a + b + c = ssum = " << ssum << " OOPS" << endl;
	int csum = a + b + c;
	cout << "INFO: a + b + c = csum = " << csum << " OK" << endl;

	/* ================================================================================== */
	/*  sc_int<w> & sc_bigint<w> */
	cout << std::string(40,'-') << endl;

	cout << "INFO: Adding 3 sc_ints to produce a bigger sc_int" << endl;
	sc_int<3> d(3);
	sc_int<5> e(15);
	sc_int<5> f(14);
	cout << "INFO: sc_int<3> d = " << d << endl;
	cout << "INFO: sc_int<5> e = " << e << endl;
	cout << "INFO: sc_int<5> f = " << f << endl;
	cout << "INFO: d + e + f = " << d + e + f << " OK" << endl;
	sc_int<7> sum = d + e + f;
	cout << "INFO: d + e + f = sum = " << sum << " OK" << endl;

	cout << std::string(40,'-') << endl;
	cout << "INFO: Adding 3 sc_ints to produce an sc_bigint" << endl;
	sc_int<64> g("0x7000000000000000");
	sc_int<64> h("0x7000000000000000");
	sc_int<64> i("0x1000000000000000");
	sc_bigint<70> bigsum;
	cout << "INFO: sc_int<3> g = " << g << endl;
	cout << "INFO: sc_int<5> h = " << h << endl;
	cout << "INFO: sc_int<5> i = " << i << endl;
	cout << "INFO: g + h + i = " << g + h + i << " OOPS" << endl;
	bigsum = g + h + i;
	cout << "INFO: g + h + i = bigsum = " << bigsum << " OOPS" << endl;
	bigsum = sc_bigint<70>(g) + h + i;
	cout << "INFO: g + h + i = bigsum = " << bigsum << " OK" << endl;

/* ================================================================================== */
	/*  sc_uint<w> & sc_biguint<w> */
	cout << std::string(40,'-') << endl;

	cout << "INFO: Adding 3 sc_uints to produce a bigger sc_uint" << endl;
	sc_uint<3> j(3);
	sc_uint<5> k(15);
	sc_uint<5> l(14);
	cout << "INFO: sc_uint<3> j = " << j << endl;
	cout << "INFO: sc_uint<5> k = " << k << endl;
	cout << "INFO: sc_uint<5> l = " << l << endl;
	cout << "INFO: j + k + l = " << j + k + l << " OK" << endl;
	sc_uint<7> usum = j + k + l;
	cout << "INFO: j + k + l = usum = " << usum << " OK" << endl;

	cout << std::string(40,'-') << endl;
	cout << "INFO: Adding 3 sc_uints to produce an sc_biguint" << endl;
	sc_uint<64> m("0x7000000000000000");
	sc_uint<64> n("0x7000000000000000");
	sc_uint<64> o("0x3000000000000000");
	sc_biguint<70> bigusum;
	cout << "INFO: sc_uint<3> m = " << m << endl;
	cout << "INFO: sc_uint<5> n = " << n << endl;
	cout << "INFO: sc_uint<5> o = " << o << endl;
	cout << "INFO: m + n + o = " << m + n + o << " OOPS" << endl;
	bigusum = m + n + o;
	cout << "INFO: m + n + o = bigusum = " << bigusum << " OOPS" << endl;
	bigusum = sc_biguint<70>(m) + n + o;
	cout << "INFO: m + n + o = bigusum = " << bigusum << " OK" << endl;

	cout << std::string(40,'-') << endl;
	cout << "INFO: The end" << endl;

	return 0;
}
