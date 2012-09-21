#ifndef FACTORY_H
#define FACTORY_H
/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 * Factory is a singleton
 *
 * @file Factory.h
 */

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <map>


class Base;

class Factory
{
public:
  typedef boost::function<Base*()> TpCreateFn;
  Base* createBaseObject(int);
  bool registerCreate(const int,TpCreateFn);


  
  static Factory* Instance()
  {
    if(!TheFactory)
      TheFactory = new Factory;
    return TheFactory;
  }
  


private:
  static Factory* TheFactory;
  Factory();
  std::map<int,TpCreateFn> m_createMap;
    
};
#endif


