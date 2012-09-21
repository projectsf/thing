/**
 * Class used in feedback_sc_main.cpp example
 *
 * @file Source.h
 */
#include "systemc.h"
#include <iostream>



class Source : public sc_module
{
public:

  sc_fifo_out<bool> dataOut;

  //typedef needed by sc_module
  typedef Source SC_CURRENT_USER_MODULE;

  Source(sc_module_name name, unsigned int numWrites, bool printEnabled = false)
    : sc_module(name),
      m_numWrites(numWrites),
      m_count(0),
      m_printEnabled(printEnabled)

  {
    SC_THREAD(execute);
  }

  void execute()
  {
    bool outData = true;
    while(m_count < m_numWrites)
    {
      outData = !outData;
      dataOut.write(outData);
      if(m_printEnabled)
        std::cout << "Source Writing a: " << outData << " to output" << std::endl;
      ++m_count;
    }
  }

private:
  unsigned int m_numWrites;
  unsigned int m_count;
  bool m_printEnabled;


};
