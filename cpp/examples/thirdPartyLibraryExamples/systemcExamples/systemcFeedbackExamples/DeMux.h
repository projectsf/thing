/**
 * Class used in feedback_sc_main.cpp example
 *
 * @file DeMux.h
 */
#include "systemc.h"
#include <iostream>



class DeMux : public sc_module
{
public:

  sc_fifo_in<bool> dataIn;
  sc_fifo_out<bool> dataOutOne;
  sc_fifo_out<bool> dataOutTwo;

  //typedef needed by sc_module
  typedef DeMux SC_CURRENT_USER_MODULE;

  DeMux(sc_module_name name, bool printEnabled = false)
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
        std::cout << "DeMux read a: " << temp << " from input " << std::endl;
      dataOutOne.write(temp);
      dataOutTwo.write(!temp);
      if(m_printEnabled)
        std::cout << "DeMux wrote a: " << temp << " and a: " << (!temp) << " to outputs" << std::endl;
    }
  }


private:
  bool m_printEnabled; 

};
