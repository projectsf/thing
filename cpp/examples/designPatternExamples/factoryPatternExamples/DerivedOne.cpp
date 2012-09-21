/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 * @file DerivedOne.cpp
 */

#include "DerivedOne.h"
#include "Factory.h"


DerivedOne::DerivedOne()
  : Base("DerivedOne")
{}

namespace
{
  Base* create()
  {
    return new DerivedOne;
  }
  
  const int KEY = 1;
  const bool REGISTERED = Factory::Instance()->registerCreate(KEY,create);
}
