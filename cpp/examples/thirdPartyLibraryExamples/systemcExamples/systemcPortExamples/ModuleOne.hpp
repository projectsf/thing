/**
 * Used in port_sc_main.cpp example
 *
 * @file ModuleOne.hpp
 */
 
#include <systemc.h>
#include <iostream>
#include <boost/shared_ptr.hpp>

template<typename T>
class ModuleOne : public sc_module {
public:
  typedef ModuleOne  SC_CURRENT_USER_MODULE;
 
  // No port for the done. 
  //sc_fifo_out<boost::shared_ptr<T> > done;
  sc_fifo_out<T> done;
 
  ModuleOne(const sc_module_name& name)
    : sc_module(name),
      //spT( new T(3) ),
      aT( T(8) ),
      NUM_ITERATIONS(16)
  {
    
    SC_THREAD(execute); 
  } 
 
  void execute()
  {
    for(unsigned int ii=0;ii<NUM_ITERATIONS;++ii) {
      std::cout << "ModuleOne execute()" << std::endl;
      //spT->setValue(ii);
      aT.setValue(ii);
      //done.write(spT);
      done.write(aT);
    }
  }

private:
  //boost::shared_ptr<T> spT;
  T aT;
  const unsigned int NUM_ITERATIONS;
};

