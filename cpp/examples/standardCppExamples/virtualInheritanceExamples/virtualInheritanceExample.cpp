/**
 * Example illustrates usage of virtual inheritance
 * Example created because a bet was made between Steve
 * and I.
 * Steve says:
 * A derived class using virtual inheritance will
 * still have a unique copy of the base class object
 * Scott says:
 * Nope.
 * Result:
 * Steve was right.
 * Virtual inheritance just insures that there is
 * am ambiguity when accessing a base class
 * of two classes that are multiply inherited from.
 * Without the "virtual" keyword, the code
 * doesn't compile.
 *
 * @file virtualInheritanceExample.cpp
 * @author Scott Maroney
 */

#include <iostream>
#include <string>
#include "DerivedOne.h"
#include "DerivedTwo.h"
#include "Join.h"


int main(int argc, char* argv[])
{
  DerivedOne d1;
  DerivedTwo d2;
  Join j1;
  d1.setName("Free beer for Scott");
  d2.setName("Free beer for Scott");
  j1.setName("Free beer for Steve");
  std::cout << j1.getName() << std::endl;
}
