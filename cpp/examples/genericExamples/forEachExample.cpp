/** Test code examines for_each and std::mem_fun
 * generic functions and looks at function
 * template specialization.
 *
 * Lessons learned:
 * <ul>
 * <li> Function templates can be specialized
 * and work in this example.
 * <li> It is possible to use std::for_each on
 * elements in a vector if those objects
 * have member functions to call.  <br>
 * Most of our applications involve
 * vectors of built-in types.  for_each
 * doesn't seem like a good solution for
 * , say, printing all of the doubles
 * in a vector.
 * <li> mem_fun maps a class member function
 * to a functor that can be used by for_each.
 * mem_fun expects a pointer to the member
 * function, thus the address of the
 * member function must be passed to mem_fun()
 * </ul>
 *
 * @file forEachExample.cpp
 */


#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <functional>

using namespace std;

//function template of type T
template<typename T1>
void printString(vector<T1> inVec)
{
  cout << "I'm a generic vector of T1" << endl;
}

//a explicit specialization of the function template printString
template<typename T1>
void printString(vector<complex<T1> > inVec)
{
  cout << "I'm a vector of complex<T1> >" << endl;
}

//a explicit specialization of the function template printString
template<>
void printString(vector<complex<int> > inVec)
{
  cout << "I'm a vector of complex<int> >" << endl;
}

class Class
{
public:
  Class(int in)
    : myInt(in)
  { cout << "initialized myInt to : " << myInt  << endl;}
  void printElement()
  {
    cout << "printingElement myInt: " << this->myInt << endl;
  }
private:
  int myInt;
};

int main()
{
  vector<unsigned int> myUintVec;
  vector<complex<int> > myComplexIntVec;
  vector<complex<double> > myComplexDoubleVec;

  printString(myUintVec);
  printString(myComplexDoubleVec);
  printString(myComplexIntVec);

  vector<Class*> myIntVec;
  Class class1(1); 
  Class class2(2); 
  Class class3(3);
  myIntVec.push_back(&class1);
  myIntVec.push_back(&class2);
  myIntVec.push_back(&class3);

  std::for_each( myIntVec.begin(), myIntVec.end(), std::mem_fun(Class::printElement) );

}
