#ifndef __FIR_H__
	#define __FIR_H__

	#include "ac_fixed.h"
	#include "ac_channel.h"

	// Add typedefs here
	typedef ac_fixed<8,8,true,AC_RND,AC_SAT> d_type ;
	typedef ac_fixed<16,1,true,AC_RND> c_type ;
	typedef ac_fixed<8+16+6,8+1+6,true> a_type ;

	void my_filter (
		ac_channel<d_type> &data_in,
		c_type coeffs[64],
		ac_channel<d_type> &data_out
		) ;

#endif

