/**
 * Example illustrates usage of boost::signals
 *
 * @file boostSignalsExample.cpp
 */


#include <iostream>
#include "boost/signal.hpp"
#include "boost/shared_ptr.hpp"

struct HelloWorld 
{
  void operator()() const
  {
    std::cout << "Hello, World!" << std::endl;
  }
};

// ...

int main()
{
  // Signal with no arguments and a void return value
  boost::signal<void ()> sig;

  // Connect a HelloWorld slot
  HelloWorld hello;
  sig.connect(hello);

  // Call all of the slots
	sig();

}


