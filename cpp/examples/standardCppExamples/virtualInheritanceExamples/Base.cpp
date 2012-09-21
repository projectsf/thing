/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 *
 * @file Base.cpp
 */

#include "Base.h"

Base::Base()
  : m_name("Initial Value")
{}

void Base::setName(const std::string& name)
{
  m_name = name;
}

std::string Base::getName() const
{
  return m_name;
}
