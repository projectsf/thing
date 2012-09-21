/** Example investigating whether itpp can hold user-defined types
 *
 * @file itppVecOfUserDefinedClass.cpp
 */

#include "itpp/itbase.h"

class UserType
{
public:
  UserType()
    : a(1),
      b(2)
  {
  }
  UserType(int in1, int in2)
    : a(in1),
      b(in2)
  {
  }

  //copy constructor
  UserType(UserType& rhs)
  {
    a = rhs.a;
    b = rhs.b;
  }

  //assignment operator
  const UserType& operator=(UserType& rhs)
  {
    a = rhs.a;
    b = rhs.b;
  }

  void printElements()
  {
    std::cout << a << '\n';
    std::cout << b << '\n';
  }

private:
  int a,b;
};

int main()
{
  itpp::Vec<UserType> myVec(3);
  
  
  myVec[0].printElements();
  myVec[1].printElements();
  myVec[2].printElements();
}
