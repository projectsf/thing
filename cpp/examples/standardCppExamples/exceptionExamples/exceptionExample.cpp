/**
 * Example illustrates how std::exceptions are thrown and caught
 *
 * Lessons Learned:
 * <ul>
 * <li> Catching std::exception& by reference, allows any exception
 * that inherits from std::exception to be caught.
 * Catching by value will "slice".
 * <li> std::runtime_error(std::string) accepts a string parameter, which
 * can be used to communicate information about the exceptional event.
 * <li> Exception class information resides in <stdexcept>
 * </ul>
 *
 * @file exceptionExample.cpp
 */

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {
    std::cout << "Throwing first exception" << '\n';
    throw std::runtime_error("Throwing runtime error exception");
  }

  catch(std::exception& exc)
  {
    std::cout << "Caught first exception" << '\n';
    std::cout << exc.what() << '\n';
  }
}
