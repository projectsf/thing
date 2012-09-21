/**
 * Example illustrates how often the copy
 * constructor is called during different
 * function call signatures
 *
 * Lessons learned
 * <ul>
 * <li> None documented
 * </ul>
 *
 * @file copyConstructor.cpp
 * @author Scott Maroney
 */

#include <iostream>

/**
 * MyContainer class prints to std out during copies and assigns
 *
 * @class MyContainer
 */
class MyContainer
{
public:

  /**
   * Empty constructor
   */
  MyContainer()
  {
  }

  /**
   * Copy constructor prints to std out when called
   */
  MyContainer(const MyContainer& rhs)
  {
    std::cout << "Calling copy constructor" << '\n';
  }

  /**
   * Assignment operator prints to screen when called
   */
  const MyContainer& operator=(const MyContainer& rhs)
  {
    std::cout << "Calling assignment operator" << '\n';
    return rhs;
  }
};

/**
 * Global copy by reference function
 *
 * @param myc const MyContainer reference parameter
 * @return a const reference to a MyContainer object
 */
const MyContainer& myCopyByRef(const MyContainer& myc)
{
  std::cout << "In: const MyContainer& myCopyByRef(const MyContainer&)" << '\n';
  return myc; 
}

/**
 * Global copy by value function
 *
 * @param myc const MyContainer parameter
 * @return a new MyContainer object
 */
MyContainer myCopyByVal(const MyContainer myc)
{
  std::cout << "In: MyContainer myCopyByVal(const MyContainer)" << '\n';
  return myc;
}

int main()
{
  //declare and construct two MyContainer's
  MyContainer cont1, cont2;

  //analyze copying by reference 
  std::cout << "Calling Copy by Reference function that returns a reference " << '\n';
  cont2 = myCopyByRef(cont1);
  std::cout << "Notice that only the assignment operator is called" << std::endl;

  std::cout << " ------------------------------------- " << std::endl;
  std::cout << " ------------------------------------- " << std::endl;

  //analyze copying by value
  std::cout << "Calling copy by value function that returns an object" << '\n';
  cont2 = myCopyByVal(cont1);
  std:: cout << "Notice that the copy constructor is called for: " << std::endl;
  std:: cout << "The input parameter copy and the return object copy" << std::endl;
}
