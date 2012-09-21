/**
 * Used in timeModeling_sc_main.cpp modeling example
 *
 * @dontinclude Consumer.hpp
 */
#include <systemc.h>
#include <iostream>
using namespace std;

//Consumer or the done signal: 

template<typename ScType>
class Consumer : public sc_module{
public:
  typedef Consumer  SC_CURRENT_USER_MODULE;
  ScType done;
 
  Consumer(const sc_module_name& name, unsigned int delay = 10)
    : sc_module(name),
      done("done"),
      blockDelay(delay)

  {
    SC_THREAD(execute);
  } 
 
  void execute(){
    done.read();
    std::cout << "Consumer begin execute() at time: " << sc_time_stamp() << " and delta count = " << sc_delta_count() << std::endl;
    wait(blockDelay, SC_NS);
    std::cout << "Consumer finished execute() at time: " << sc_time_stamp() << " and delta count = " << sc_delta_count() << std::endl;
  }

private:
  unsigned int blockDelay;
};
