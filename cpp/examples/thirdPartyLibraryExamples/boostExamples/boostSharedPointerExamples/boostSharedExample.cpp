/**
 * Illustrates the use of boost shared pointers
 *
 * Does a shared_ptr destroy the memory created
 * newed by a dump pointer?
 *
 * @file boostSharedExample.cpp
 */

#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>


class Shape
{
public:
  Shape(const std::string& name)
  : m_name(name)
  {}
  ~Shape() { std::cout << "Destroying .." << std::endl; }
  
private:
  std::string m_name;
};


int main()
{
  Shape* pShape = new Shape("Shape");
{
  boost::shared_ptr<Shape> spShape(pShape);
}
std::cout << "Boost shared pointer out of scope" << std::endl;
}



