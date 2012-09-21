/**
 * Class used in classHierarchy_sc_main.cpp example
 *
 * @file Sink.h
 */
#include "systemc.h"
#include "BaseClass.h"
#include <iostream>



class Sink: public BaseClass
{
public:

  sc_fifo_in<bool> dataIn;

  //typedef needed by sc_module
  typedef Sink SC_CURRENT_USER_MODULE;

  Sink(sc_module_name name)
    : BaseClass(name)
  {
  }

  void execute()
  {
    while(true)
    {
      bool temp;
      dataIn.read(temp);
      std::cout << "Read a: " <<  temp << " in Sink"  << std::endl;
    }
  }

  void printSomething()
  {
    std::cout << "In printSomething() for Sink" << std::endl;
  }


};
