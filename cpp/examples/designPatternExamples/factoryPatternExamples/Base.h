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
  Base(char* name);
  void printMe();
private:
  std::string m_name;
};
#endif


