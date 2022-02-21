#include <systemc.h>
#include "interfaces.h"
#include "tlm_tlc.h"
#include "os_drivers.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<bool> car;
	sc_signal<color> M, S;

	TLC_SW TLC("Controller");
	OS_DRIVERS os_drivers("OS_drivers");

	os_drivers.car(car);
	os_drivers.M(M);
	os_drivers.S(S);
	
	TLC.car(os_drivers);
	TLC.light(os_drivers);
	TLC.timer(os_drivers);

	sc_start();
	return 0;
}
