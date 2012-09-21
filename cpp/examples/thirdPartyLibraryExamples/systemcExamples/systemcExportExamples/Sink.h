/**
 * Code used in scExport_sc_main.cpp example
 *
 * @file Sink.h
 */
 
#include "systemc.h"
#include <iostream>



class Sink: public sc_module
{
public:

  sc_fifo_in<bool> dataIn;

  //typedef needed by sc_module
  typedef Sink SC_CURRENT_USER_MODULE;

  Sink(sc_module_name name)
    : sc_module(name),
      count(0),
      startSinkingCount(5)

  {
    SC_HAS_PROCESS(Sink);
    SC_THREAD(execute);
  }

  void execute()
  {
    while(true)
    {
      if(count <= startSinkingCount)
      {
        dataIn.read();
        //std::cout << "Read a: " <<  dataIn.read() << " in Sink"  << std::endl;
        count++;
      }
      else
      {
        dataIn.read();
        //std::cout << "Sunk a: " <<  dataIn.read() << " in Sink"  << std::endl;
      }
    }
  }

private:
  unsigned int count;
  const unsigned int startSinkingCount;

};
