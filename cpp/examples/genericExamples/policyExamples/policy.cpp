/**
 * Example illustrates how to implement policies
 * with templates.  Policies are templated
 * versions of the Strategy Design Pattern
 *
 * Mostly comes out of Alexandrescu's Modern C++
 * design book.
 *
 * Also included is a classic OO design approach
 * with virtual functions.
 *
 * Lessons learned
 * <ul>
 * <li> Policy implemented with templates is very useful in
 * our UWB model development because we can't use OO run-time
 * polymorphism since different ModuleBase objects have
 * different template types.
 * </ul>
 *
 * @file policy.cpp
 * @author Scott Maroney
 */

#include <iostream>

class Policy
{
public:
  virtual void printMe() = 0;
};
    
class PolicyOne : public Policy
{
public:
  void printMe() {std::cout << "I'm numberOne" << std::endl; }
};

class PolicyTwo : public Policy
{
public:
  void printMe() {std::cout << "I'm numerTwo" << std::endl; }
};

template <typename T, class PrintPolicy = PolicyOne>
class Print : public PrintPolicy
{
};



int main()
{
  Print<int> myPrintOne;
  Print<int,PolicyTwo> myPrintTwo;
  Policy* myPolicy = new PolicyOne;

  myPolicy->printMe();

  myPrintOne.printMe();
  myPrintTwo.printMe();

  delete myPolicy;
}

