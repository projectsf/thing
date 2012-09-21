/**
 * Example illustrates polymorphism in vectors
 *
 * Lessons Learned:
 * <ul>
 * <li> To use dynamic_cast<T> a virtual function must be
 * defined
 * <li> You must downcast to access derived functionality
 * of a derived class object that is stored in a vector<BasePtr>
 * <li> Dumb pointers don't support the notion of value semantics.
 * The Standard Library requires that any T T1 in a STL container
 * possess value semantics, i.e. T must be assignable (operator=() )
 * and copyConstructible T T1(T2).
 * Consider this:
 *   MyType* pMyType(new MyType);
 *   pMyType = 0;
 * The memory allocated for the MyType object was created and
 * never destroyed.  Dumb pointers that point to objects
 * created with a "new" call, "own" that object.  Unfortunately,
 * dumb pointers can be reassigned, leaving the dangling object
 * undestroyed. <br>
 * SmartPointers offer ownership management, which insures
 * that any objects that are created are properly destroyed
 * when they are not referenced. <br>
 * This example uses Boost's shared_ptr.
 * <li> Boost has a dynamic cast dynamic_pointer_cast
 * that can be used to cast a base class smart pointer
 * to a derived class smart pointer.
 * </ul>
 *
 * @file polymorphicContainerExample.cpp
 */

#include <iostream>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>


class Base
{
public:
  Base()
    : m_baseValue(1),
    baseName("I'm a base")
  {
  }
  virtual std::string getName() const
  {
    return baseName;
  }
  
  int getBaseValue() const
  {
    return m_baseValue;
  }
private:
  int m_baseValue;
  std::string baseName;
};


class Derived : public Base
{
public:
  Derived()
    : m_derivedValue(7),
      derivedName("I'm a derived")
  {
  }

  virtual std::string getName() const
  {
    return derivedName;
  }
  
  int getDerivedValue() const
  {
    return m_derivedValue;
  }

  
  
private:
  int m_derivedValue;
  std::string derivedName;
};

typedef boost::shared_ptr<Base> BasePtr;
typedef boost::shared_ptr<Derived> DerivedPtr;

int main()
{
  std::vector<BasePtr> myVec;
  myVec.push_back(BasePtr(new Derived) );
  myVec.push_back(BasePtr(new Base) );

  for(std::vector<BasePtr>::iterator iter = myVec.begin();
      iter!=myVec.end();
      ++iter)
  {
    std::cout << (*iter)->getName() << std::endl;
    if( DerivedPtr pDerived = boost::dynamic_pointer_cast<Derived>(*iter) )
      std::cout << pDerived->getDerivedValue() << std::endl;
    else
      std::cout << (*iter)->getBaseValue() << std::endl;
  }
  
}
