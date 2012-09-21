/**
 * Example illustrates usage of <typeinfo> (RTTI) library
 *
 * Lessons Learned
 * <ul>
 * <li> RTTI library is <typeinfo>
 * <li> typeid(variableName).name() returns a string
 * describing the type.  String for std::complex<T>
 * type has "complex" in the name.  Additional
 * characters are non-sensical.
 * </ul>
 *
 * @file typeInfoExample.cpp
 * @author Scott Maroney
 */

#include <iostream>
#include <vector>
#include <complex>
#include <typeinfo>
#include <string>


template<typename T>
T returnMe(int in)
{
  std::string typeName = typeid(T).name(); 
  std::cout << typeName << std::endl;
  if( (typeName.find("complex") != std::string::npos) )
  {
    std::cout << "it's complex" << std::endl;
    return static_cast<T>(in);
  }
  else
  {
    std::cout << "it's not complex" << std::endl;
    return static_cast<T>(in);
  }

}


int main()
{
  int myI = 3;

  std::cout << returnMe<int>(myI) << std::endl;
  std::cout << returnMe<std::complex<double> >(myI) << std::endl;
  std::cout << returnMe<std::complex<int> >(myI) << std::endl;
  std::cout << returnMe<std::complex<unsigned int> >(myI) << std::endl;
  std::cout << returnMe<std::complex<std::complex<bool> > >(myI) << std::endl;
}
