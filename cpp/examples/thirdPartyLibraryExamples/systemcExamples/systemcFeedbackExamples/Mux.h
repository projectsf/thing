/**
 * Class used in feedback_sc_main.cpp example
 *
 * @file Mux.h
 */

#include "systemc.h"
#include <iostream>



class Mux : public sc_module
{
public:

  sc_fifo_in<bool> dataInOne;
  sc_fifo_in<bool> dataInTwo;
  sc_fifo_out<bool> dataOut;

  //typedef needed by sc_module
  typedef Mux SC_CURRENT_USER_MODULE;

  Mux(sc_module_name name, unsigned int blockSize, bool printEnabled = false)
    : sc_module(name),
      m_muxSelect(true),
      m_readCount(0),
      m_blockSize(blockSize),
      m_printEnabled(printEnabled)
  {
    SC_THREAD(execute);
  }

  void execute()
  {
    while(true)
    {
      bool tempOne, tempTwo;
      dataInOne.read(tempOne);
      if(m_printEnabled)
        std::cout << "Mux read a: " << tempOne << " from input one " << std::endl;
      if(m_readCount == 0) {
        dataInTwo.read(tempTwo);
        if(m_printEnabled) 
          std::cout << "Mux nb_read a: " << tempTwo << " from input two " << std::endl;
        m_readCount++;
      }
      else {
        dataInTwo.read(tempTwo);
        if(m_printEnabled)
          std::cout << "Mux read a: " << tempTwo << " from input two " << std::endl;
      }
        
      if(m_muxSelect) {
        dataOut.write(tempOne);
        if(m_printEnabled)
          std::cout << "Mux wrote a: " << tempOne << " to output one" << std::endl;
      }
      else {
        dataOut.write(tempTwo);
        if(m_printEnabled)
          std::cout << "Mux wrote a: " << tempTwo << " to output two " << std::endl;
      }
      
    }
  }


private:
  bool m_muxSelect;
  unsigned int m_readCount;
  unsigned int m_blockSize;
  bool m_printEnabled;



};
