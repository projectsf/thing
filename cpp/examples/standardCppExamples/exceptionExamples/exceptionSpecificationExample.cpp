/**
 * Example illustrates what happens when a function
 * violates a throw specification
 *
 * @file exceptionSpecificationExample.cpp
 */

#include <iostream>
#include <exception>
#include <stdexcept>

void my_unexpected() 
{
  std::cerr << "myunexpected called\n";
  throw 0;     // throws int (in exception-specification)
}


void foo() throw()
{
    throw std::runtime_error("Throwing runtime error exception");
}

int main()
{
	std::set_unexpected(my_unexpected);

  try
  {
		foo();
  }

  catch(std::exception& exc)
  {
    std::cout << exc.what() << '\n';
  }
}
