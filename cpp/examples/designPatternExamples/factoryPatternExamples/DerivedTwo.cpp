/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 * @file DerivedTwo.cpp
 */

#include "DerivedTwo.h"
#include "Factory.h"

namespace
{
  Base* create()
  {
    return new DerivedTwo;
  }
  
  const int KEY = 2;
  const bool REGISTERED = Factory::Instance()->registerCreate(KEY,create);
}

DerivedTwo::DerivedTwo()
  : Base("DerivedTwo")
{}



