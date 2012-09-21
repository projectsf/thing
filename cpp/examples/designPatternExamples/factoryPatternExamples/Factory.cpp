/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 * @file Factory.cpp
 */

#include "Factory.h"
#include "Base.h"

Factory* Factory::TheFactory = 0;

Base* Factory::createBaseObject(int key)
{
  std::map<int,TpCreateFn>::const_iterator iter = m_createMap.find(key);
  if (iter == m_createMap.end() ) {
    throw std::runtime_error("ERROR: Key does not map to creation function");
  }
  return (iter->second)();
}

bool Factory::registerCreate(int key, TpCreateFn createFn)
{
  return m_createMap.insert(std::map<int,TpCreateFn>::value_type(key,createFn)).second;
}

Factory::Factory()
{}
