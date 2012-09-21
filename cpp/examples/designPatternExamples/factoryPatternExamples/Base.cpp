/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 *
 * @file Base.cpp
 */

#include "Base.h"

Base::Base(char* name)
  : m_name(name)
{}
   
void Base::printMe()
{
  std::cout << "I'm a: " << m_name << std::endl;
}
