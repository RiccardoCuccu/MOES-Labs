// testbench that compares the fixed and double implementations
#include "FIR_Reference.h"
#include "FIR_Fixed.h"
#include "coeffs.h"
#include <iostream>
using namespace std ;

int main() {

	double taps[64] = {0};
	double data_in ;
	double data_out ;

	c_type fixed_coeffs[64] ;
	for (int i=0;i<64;i++) fixed_coeffs[i] = float_coeffs[i] ;

	ac_channel<d_type> fixed_in ;
	ac_channel<d_type> fixed_out ;

	double big_diff = 0 ;

	for (int i=0;i<64*2+10;i++) {
		if (i==0) data_in = 100 ;
		else if (i >64) data_in = 100 ;
		else data_in = 0 ;
		fixed_in.write(data_in) ;

		data_out = FIR_Reference(data_in, taps, float_coeffs, 64) ;
		my_filter(fixed_in,fixed_coeffs,fixed_out) ;

		d_type fixed_data_out = fixed_out.read() ;
		double diff = data_out - (fixed_data_out.to_double()) ;
		diff = (diff<0) ? -diff : diff ;

		if (diff>big_diff) big_diff = diff ;

		cout << "Float output = " << data_out << " fixed_point = " << (fixed_data_out).to_double() << " diff = " << diff << endl ;
	}
	cout << "Worst case difference = " << big_diff << endl ;

}


