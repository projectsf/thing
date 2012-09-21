/**
 * A Source systemC module that has a sc_export used in scExport_sc_main.cpp example
 *
 * File produces data.  Data is accessible
 * through sc_export channel. <br>
 *
 * Later investigations converted sc_export<sc_fifo<T> >
 * to a non-scalar type (a ptr)
 * to help understand why a top level compile for
 * the UWB model wasn't working. <br>
 * And then later investigations put that sc_export
 * into a std::vector <br>
 *
 * file Source.h
 */

#include "systemc.h"
#include <iostream>
#include <vector>

class Source: public sc_module
{
public:
  std::vector<sc_export<sc_fifo<bool> >* > dataOutIntf;
  sc_fifo<bool> dataOut;

  sc_signal<bool> sc_start;
  sc_event startEvent;

  //typedef needed by sc_module
  typedef Source SC_CURRENT_USER_MODULE;

  Source(sc_module_name name)
    : sc_module(name),
      //dataOutIntf("dataOutIntf"),
      //dataOutIntf(initScExport()),
      dataOut("dataOut", 1000),
      start(false),
      count(1),
      stopCount(1000)
  {
    SC_HAS_PROCESS(Source);
    SC_THREAD(execute);
    //sensitive << sc_start;
    SC_THREAD(setStart);

    dataOutIntf.push_back(new sc_export<sc_fifo<bool> >("dataOutIntf") );
    
    //bount intf to channel
    (*(dataOutIntf[0]))(dataOut);

  }


  void execute()
  {
    bool outData = true;
    while(true)
    {
      if(start)
      {
        outData = !outData;
        //std::cout << "Writing a: " << outData << " to output" << std::endl;
        dataOut.write(outData);
        if(count==stopCount)
        {
          start = false;
        }
        else
        {
          count++;
        }
      }
      else
      {
        wait(startEvent);
      }
    }
  }

  void setStart(bool in)
  {
    start = in;
    startEvent.notify();
    count = 1;
  }

private:
  bool start;
  unsigned int count;
  unsigned int stopCount;

};
