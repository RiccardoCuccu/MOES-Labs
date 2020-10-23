#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
#include <string>
#include "EX_sc_time.h"

void EX_sc_time::time_thread(void) {
  cout << "INFO: Time resolution is " << sc_get_time_resolution() << endl;
  const sc_time t_1FS(1,SC_FS);
  const sc_time t_1S(1,SC_SEC);
  const sc_time t_1HR(3600*t_1S);// computed time
  sc_time t_DELAY(t_1FS);
  // Delay by powers of ten and display the resulting time
  for (;t_DELAY<=2*t_1HR;t_DELAY*=10) {
    cout << "INFO: Delaying " << t_DELAY << " ";
    wait(t_DELAY);
    cout << "INFO: Time is " << sc_time_stamp() << "!" << endl;
  }//endfor
  for (t_DELAY=2*t_1HR;t_DELAY>=t_1FS;t_DELAY/=10) {
    cout << "INFO: Delaying " << t_DELAY << " ";
    wait(t_DELAY);
    cout << "INFO: Time now " << sc_time_stamp() << endl;
  }//endfor
  wait(SC_ZERO_TIME);
  cout << "INFO: wait(SC_ZERO_TIME)" << endl;
  cout << "INFO: Time still " << sc_time_stamp() << endl;
  #ifdef USE_STOP
  cout << "INFO: Simulation will stop at the current time." << endl;
  sc_stop();
  #else
  cout << "INFO: Simulation will now proceed to limit specified by sc_start()" << endl;
  cout << "----: which is \"the maximum simulation time allowed\"." << endl;
  #endif
}//end time_thread()

