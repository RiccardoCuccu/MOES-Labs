#ifndef __FIR_CLASS_H__
#define __FIR_CLASS_H__

#include "ac_fixed.h"
#include "ac_channel.h"

template <class dType, class cType, class aType, int N_TAPS>
class fir_filter {
	dType taps[N_TAPS];
public:
	fir_filter() {
		for (int i=0;i<N_TAPS;i++) {
			taps[i] = 0 ;
		}
	};

	void fir_filter_shift(ac_channel<dType> &data_in, cType coeffs[N_TAPS], ac_channel<dType> &data_out) ;
	void fir_filter_shift_fold_even(ac_channel<dType> &data_in, cType coeffs[N_TAPS/2], ac_channel<dType> &data_out) ;
} ;

template <class dType, class cType, class aType, int N_TAPS>
void fir_filter<dType, cType, aType, N_TAPS>::fir_filter_shift(
	ac_channel<dType> &data_in,
	cType coeffs[N_TAPS],
	ac_channel<dType> &data_out
) {

// Fill in the blanks here
	aType acc = 0 ;

	SHIFT:for (int i=(N_TAPS-1); i>=0; i--) {
		taps[i] = (i==0) ? data_in.read() : taps[i-1] ;
	}

	MAC:for (int i=(N_TAPS-1); i>=0; i--) {
		acc += taps[i] * coeffs[i] ;
		}

	data_out.write(acc) ;
}


template <class dType, class cType, class aType, int N_TAPS>
void fir_filter<dType, cType, aType, N_TAPS>::fir_filter_shift_fold_even(
	ac_channel<dType> &data_in,
	cType coeffs[N_TAPS/2],
	ac_channel<dType> &data_out
) {

	aType acc = 0 ;	

	SHIFT:for(int i=(N_TAPS-1);i>=0;i--) {
		if (i==0) taps[i] = data_in.read() ;
		else taps[i]=taps[i-1] ;
	}

	aType fold[N_TAPS/2] ;

	FOLD:for(int i=(N_TAPS/2)-1;i>=0;i--) {
		fold[i] = taps[i] + taps[N_TAPS-1-i] ;
	}

	MAC:for(int i=(N_TAPS/2)-1;i>=0;i--) {
		acc += coeffs[i] * fold[i] ;
	}

	data_out.write(acc) ;
}

#endif
