#include "FIR_Class.h"
#include "FIR_Fixed.h"

#pragma hls_design top 
void my_filter (
	ac_channel<d_type> &data_in,
	c_type coeffs[64],
	ac_channel<d_type> &data_out
	) {

	static fir_filter<d_type,c_type,a_type,64> filter ;

	filter.fir_filter_shift(data_in,coeffs,data_out) ;

}
