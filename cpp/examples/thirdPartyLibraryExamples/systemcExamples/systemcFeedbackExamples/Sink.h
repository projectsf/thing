/**
 * Class used in feedback_sc_main.cpp example
 *
 * @file Sink.h
 */

#include "systemc.h"
#include <iostream>



class Sink : public sc_module
{
public:

  sc_fifo_in<bool> dataIn;

  //typedef needed by sc_module
  typedef Sink SC_CURRENT_USER_MODULE;

  Sink(sc_module_name name, bool printEnabled = false)
    : sc_module(name),
      m_printEnabled(printEnabled)
  {
    SC_THREAD(execute);
  }

  void execute()
  {
    while(true)
    {
      bool temp;
      dataIn.read(temp);
      if(m_printEnabled)
        std::cout << "Sink read a: " <<  temp << " in Sink"  << std::endl;
    }
  }

private:
  bool m_printEnabled;


};
