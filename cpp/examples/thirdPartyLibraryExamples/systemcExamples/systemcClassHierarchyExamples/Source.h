/**
 * Class used in classHierarchy_sc_main.cpp example
 *
 * @file Source.h
 */
#include "systemc.h"
#include "BaseClass.h"
#include <iostream>



class Source : public BaseClass
{
public:

  sc_fifo_out<bool> dataOut;

  sc_signal<bool> sc_start;
  sc_event startEvent;


  //typedef needed by sc_module
  typedef Source SC_CURRENT_USER_MODULE;

  Source(sc_module_name name)
    : BaseClass(name),
      start(false),
      count(1),
      stopCount(1)
  {
    SC_THREAD(setStart);
  }

  void execute()
  {
    bool outData = true;
    while(true)
    {
      if(start)
      {
        outData = !outData;
        dataOut.write(outData);
        std::cout << "Writing a: " << outData << " to output" << std::endl;
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

  void printSomething()
  {
    std::cout << "In printSomething() for Source" << std::endl;
  }

private:
  bool start;
  unsigned int count;
  unsigned int stopCount;

};
