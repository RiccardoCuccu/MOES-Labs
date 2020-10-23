#include "systemc.h"
using std::cout;
using std::endl;
#include "EX_sc_time.h"
using namespace sc_core;

int sc_main(int argc, char* argv[]) {
  sc_set_time_resolution(1,SC_FS);
  //sc_set_default_time_unit(1,SC_SEC);  //deprecated
  
  cout << "Time resolution is "   << sc_get_time_resolution()  << endl;
  //cout << "Default time unit is " << sc_get_default_time_unit() << endl; //deprecated
  
  EX_sc_time time_inst("time_inst");
  
  cout << "Starting EX_sc_time simulation" << endl;
  
  sc_start();

  cout << "Exiting EX_sc_time simulation." << endl;
  cout << "Simulator finished at " 
       << time_inst.display_hms(sc_time_stamp())
       << endl;
  // Nothing to fail, so we exit with an unconditional OK
  return 0;
}
