/**
 * Used in systemC sc_trace  example
 *
 * @file Producer.hpp
 */
#include <systemc.h>
#include <iostream>


template<class ScType>
class Producer : public sc_module {
public:
  typedef Producer  SC_CURRENT_USER_MODULE;
 
  // Output port
  ScType out;
 
  Producer(const sc_module_name& name, unsigned int delay = 10)
    : sc_module(name),
      out("out"),
      blockDelay(delay),
      count(10)
  {
    
    SC_THREAD(execute); 
  } 
 
  void execute(){
    while (--count > 0) {
      out.write(count);
      wait(blockDelay, SC_NS);
    }

  }

private:
  unsigned int blockDelay;
  int count;
};

