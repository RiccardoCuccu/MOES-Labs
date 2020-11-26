// testbench
#include "FIR_Reference.h"
#include "coeffs.h"
#include <iostream>
using namespace std ;

int main() {

	double taps[64] ;

	double data_in ;
	double data_out ;

	for (int i=0;i<64*2+10;i++) {
		if (i==0) data_in = 100 ;
		else if (i >64) data_in = 100 ;
		else data_in = 0 ;

		data_out = FIR_Reference(data_in, taps, float_coeffs, 64) ;

		cout << "output = " << data_out << endl ;
	}

}
