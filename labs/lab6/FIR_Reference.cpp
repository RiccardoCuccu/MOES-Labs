// A programmable floating point C++ reference FIR filter with external taps

double FIR_Reference (
	double data_in,
	double *taps,
	const double *coeffs,
	int num_taps
	) {

	double acc = 0 ;

	for (int i=(num_taps-1); i>=0; i--) {
		taps[i] = (i==0) ? data_in : taps[i-1] ;
	}

	for (int i=(num_taps-1); i>=0; i--) {
		acc += taps[i] * coeffs[i] ;
	}

	return acc ;

}
