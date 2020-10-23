#include "BasicModule.h"

void BasicModule::ex_thread_process(void) {	// implementation of member function (process)
  // print the name of the current SystemC module instance
  std::cout << "ex_thread_process executed within " << name() << std::endl;
  // It is the same as 
  // printf("ex_thread_process executed within %s\n",name().c_str());
}
