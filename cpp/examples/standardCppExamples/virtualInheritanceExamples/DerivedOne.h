#ifndef DERIVEDONE_H
#define DERIVEDONE_H
/**
 * Illustrates usage of Factory Design Pattern
 *
 * Used in factoryPatternExample.cpp
 * @file DerivedOne.h
 */

#include "Base.h"

class DerivedOne : public virtual Base
{
public:
  DerivedOne();
};
#endif
