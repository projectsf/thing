/**
 * Illustrates usage of Factory Design Pattern
 *
 * This object factory implementation mimics the
 * implementation found in Alexandrescu's Modern
 * C++ design, pages 204-205. <br>
 * The factory is also a singleton
 * (class using static pointers and an Instance()
 * function that returns a static pointer).
 * The factory stores a map<key,value> with the value
 * being create functions defined by the classes
 * that the factory wants to make objects out of.
 * The classes register with the singleton factory
 * using "startup" code that is hidden in an
 * anonymous namespace in the implementation (cpp)
 * file of the class.
 * This startup code registers the class with the
 * object factory using a unique key.
 * A public create(unsigned int key) function is
 * exposed in the factory that returns a new object
 * based on a key.  The object is created by calling
 * the creation function in the std::map.
 *
 * @file factoryPatternExample.cpp
 * @author Scott Maroney
 */

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include "Factory.h"
#include "Base.h"

int main(int argc, char* argv[])
{
  if(argc != 2) {
    std::cerr << "Incorrect number of arguments.  Expecting 2." << std::endl;
    exit(1);
  }
  
  int key = atoi(argv[1]);
  boost::shared_ptr<Base> pBase;
  
  try {
    pBase = boost::shared_ptr<Base>(Factory::Instance()->createBaseObject(key));
  }
  catch(std::exception& exc) {
    std::cout << exc.what() << std::endl;
    exit(1);
  }

  pBase->printMe();
}
