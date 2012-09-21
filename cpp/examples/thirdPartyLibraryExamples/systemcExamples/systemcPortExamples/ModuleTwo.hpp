/**
 * Used in port_sc_main.cpp example
 *
 * @file ModuleTwo.hpp
 */
#include <systemc.h>
#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;

//Consumer or the done signal: 
template<typename T>
class ModuleTwo : public sc_module
{
public:
  typedef ModuleTwo  SC_CURRENT_USER_MODULE;
  //sc_fifo_in<boost::shared_ptr<T> > done;
  sc_fifo_in<T> done;
 
  ModuleTwo(const sc_module_name& name)
    : sc_module(name)
  {
    SC_THREAD(execute);
    sensitive << done;
  } 
 
  void execute()
  {
    while(1) {
      //boost::shared_ptr<T> temp = done.read();
      T temp = done.read();
      //std::cout << "ModuleTwo execute(), read: " << temp->getValue() << std::endl;
      std::cout << "ModuleTwo execute(), read: " << temp.getValue() << std::endl;
    }
  }
};
