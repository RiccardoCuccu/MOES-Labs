#include "systemc.h"
#include <string>
using std::string;
using namespace::sc_core;

SC_MODULE(EX_sc_time) {

	SC_CTOR(EX_sc_time) {
		SC_THREAD(time_thread);		// register process
	}
  
  void time_thread(void);

};
