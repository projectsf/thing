/**
 * Code analyzes how static_cast operates
 *
 * Code investigated how static_cast operates
 *
 * Lessons learned:
 * <ul>
 * <li> static_cast simply calls the copy constructor <br>
 * For example: <br>
 * T2_value = static_cast<T2> (T1_value); <br>
 * Calls:
 * T2(const T1&) constructor for T2. <br>
 * If it's not defined, the cast doesn't work <br>
 * </ul>
 *
 * @file staticCast.cpp
 */

#include <iostream>
#include <string>

/**
 * Empty class A
 */
class A
{
public:
    
  A()
    : me("I'm an A")
  {
  }

  void printMe()
  {
    std::cout << me << std::endl;
  }

  std::string getMe() const
  {
    return me;
  }

private:
  std::string me;    
};

class B
{
public:

  B()
    : me("I'm a B")
  {
    std::cout << "Calling B() constructor" << std::endl;
  }
  
  B(const A& a)
    : me( a.getMe() )
  {
    std::cout << "Calling B(const A&) constructor" << std::endl;
  }

  void printMe()
  {
    std::cout << me << std::endl;
  }
  
private:
    std::string me;
  
};


int main()
{
  A a;
  B b;

  std::cout << "Original B: " << std::endl;
  b.printMe();
  //assign a to b
  b = static_cast<B> ( a );

  std::cout << "B after assigned a static_cast'd A: " << std::endl;
  b.printMe();

}
