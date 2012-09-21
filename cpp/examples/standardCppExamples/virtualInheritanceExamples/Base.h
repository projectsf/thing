#ifndef BASE_H
#define BASE_H
/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 *
 * @file Base.h
 */

#include <iostream>
#include <string>


class Base
{
public:
  Base();
  void setName(const std::string&);
  std::string getName() const;
private:
  std::string m_name;
};
#endif


