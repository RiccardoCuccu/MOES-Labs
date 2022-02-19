#include "tlc.h"

void TLC::proc_thread(void) {

	main_tl.write(GREEN);
	side_tl.write(RED);

	wait(1,SC_SEC);

	while(1) {

		if(!car.read()) wait(car.posedge_event());
	
		main_tl.write(YELLOW);
	
		wait(5,SC_SEC);
		main_tl.write(RED);
		side_tl.write(GREEN);

		wait(10,SC_SEC);
		side_tl.write(YELLOW);

		wait(5,SC_SEC);
		side_tl.write(RED);
		main_tl.write(GREEN);

		wait(10,SC_SEC);
	}
}