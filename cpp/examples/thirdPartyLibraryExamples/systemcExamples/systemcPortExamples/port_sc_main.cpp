/**
 * I have no idea what this example illustrates
 *
 * @file port_sc_main.cpp
 */

#include <systemc.h>
#include "ModuleOne.hpp"
#include "ModuleTwo.hpp"
#include "MyContainer.hpp"
#include <boost/shared_ptr.hpp>

std::ostream& operator<<(std::ostream& os, const MyContainer& rhs)
{
  os << rhs.getValue() << std::endl; 
  return os;
}
 
int sc_main(int argc, char *argv[])
{
  typedef MyContainer T;
  //sc_fifo<boost::shared_ptr<T> > done("SomeFifo", 1);
  sc_fifo<T> done("SomeFifo", 1);
 
  ModuleOne<T> moduleOne("module");
  moduleOne.done(done);
 
  ModuleTwo<T> moduleTwo("module2");
  moduleTwo.done(done);
 
  sc_start(1000);

  return 1;
 
}
