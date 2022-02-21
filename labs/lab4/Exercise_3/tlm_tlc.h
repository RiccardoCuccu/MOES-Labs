#ifndef TLM_TLC_H
#define TLM_TLC_H

SC_MODULE(TLC_SW) {

	sc_port<car_if> car;
	sc_port<timer_if> timer;
	sc_port<light_if> light;

	SC_CTOR(TLC_SW) {
		SC_THREAD(CONTROLLER);
	}
	
	void CONTROLLER() {
		int i = 3;
		while(i--) {
			light->set_main(GREEN);
			light->set_sec(RED);
			car->wait_for_car();
			light->set_main(YELLOW);
			timer->wait_for_sec(5);
			light->set_main(RED);
			light->set_sec(GREEN);
			timer->wait_for_sec(10);
			light->set_sec(YELLOW);
			timer->wait_for_sec(5);
		}
		sc_stop();
	}
};

#endif
