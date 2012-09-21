#ifndef JOIN_H
#define JOIN_H
/**
 * Illustrates usage of virtual inheritance
 *
 * Used in virtualInheritanceExample.cpp
 * @file Join.h
 */

#include "DerivedOne.h"
#include "DerivedTwo.h"

class Join : public DerivedOne, public DerivedTwo
{
public:
  Join();
};
#endif
