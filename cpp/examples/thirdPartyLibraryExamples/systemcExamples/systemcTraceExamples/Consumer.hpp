/**
 * Used in systemC sc_trace  example
 *
 * @file Consumer.hpp
 */
#include <systemc.h>
#include <iostream>
using namespace std;

//Consumer or the in signal:

template<typename ScType>
class Consumer : public sc_module{
public:
  typedef Consumer  SC_CURRENT_USER_MODULE;
  ScType in;
 
  Consumer(const sc_module_name& name, unsigned int delay = 10)
    : sc_module(name),
      in("in"),
      blockDelay(delay),
      count(10)

  {
    SC_THREAD(execute);
  } 
 
  void execute(){
    while (--count > 0) {
      in.read();
      wait(blockDelay, SC_NS);
    }
  }

private:
  unsigned int blockDelay;
  unsigned int count;
};
