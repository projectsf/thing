/**
 * Used in systemC time modeling example
 *
 * @file Producer.hpp
 */
#include <systemc.h>
#include <iostream>


template<class ScType>
class Producer : public sc_module {
public:
  typedef Producer  SC_CURRENT_USER_MODULE;
 
  // No port for the done. 
  ScType done;
 
  Producer(const sc_module_name& name, unsigned int delay = 10)
    : sc_module(name),
      done("doneIn"),
      blockDelay(delay)
  {
    
    SC_THREAD(execute); 
  } 
 
  void execute(){
    std::cout << "Producer began execute() at time: " << sc_time_stamp() << " and delta count = " << sc_delta_count() <<  std::endl;
    wait (blockDelay, SC_NS);
    done.write(true);
    std::cout << "Producer finished execute() at time: " << sc_time_stamp() << " and delta count = " << sc_delta_count() << std::endl;

  }

private:
  unsigned int blockDelay;
};

