/**
 * Class used in classHierarchy_sc_main.cpp example
 *
 * @file BaseClass.h
 */

#include "systemc.h"
#include <iostream>
#ifndef BASECLASS_H
#define BASECLASS_H



class BaseClass : public sc_module
{
public:

  //typedef needed by sc_module
  typedef BaseClass SC_CURRENT_USER_MODULE;

  BaseClass(sc_module_name name)
    : sc_module(name)

  {
    //SC_THREAD(printSomething);
    SC_THREAD(execute);
  }

  virtual void execute() = 0;

  virtual void printSomething() = 0;


};


#endif
