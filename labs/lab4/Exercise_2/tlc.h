#ifndef TLC_H
#define TLC_H

enum color{RED, YELLOW, GREEN};

SC_MODULE(TLC)
{
	//public :
	sc_in<bool> car;
	sc_in<bool> sec_5;
	sc_out<bool> start;
	sc_out<color> M, S;

	SC_CTOR(TLC)						// constructor
	//: car("car"), M("Main"), S("Secondary")
	{
		SC_THREAD(TLC_run);
		sensitive << car << sec_5;
	}

	void TLC_run() {
		M.write(GREEN);					// initialization
		S.write(RED);
		start.write(false);

		while (1) {	
			wait5sec();
			wait5sec();
			if (!car) wait(car.posedge_event());	// wait until car arrives at Secondary
			wait5sec();
			M.write(YELLOW);
			wait5sec();
			M.write(RED);
			S.write(GREEN);
			wait5sec();
			wait5sec();
			S.write(YELLOW);
			wait5sec();
			S.write(RED);
			M.write(GREEN);
		}
	}

	void wait5sec() {
		start.write(!start.read());
		wait(sec_5.posedge_event());
	}
};

#endif
