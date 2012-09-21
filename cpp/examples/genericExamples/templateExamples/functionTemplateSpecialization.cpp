/** Test code looks at function template specialization.
 *
 * Lessons learned:
 * <ul>
 * <li> Function templates can be specialized
 * and work in this example.
 *
 * @file functionTemplateSpecialization.cpp
 */


#include <iostream>
#include <vector>
#include <complex>

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


int main()
{
  vector<unsigned int> myUintVec;
  vector<complex<int> > myComplexIntVec;
  vector<complex<double> > myComplexDoubleVec;

  printString(myUintVec);
  printString(myComplexDoubleVec);
  printString(myComplexIntVec);

}
