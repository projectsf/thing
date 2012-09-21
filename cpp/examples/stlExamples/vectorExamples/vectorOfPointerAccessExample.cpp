/**
 * Test code illustrates how to access a vector<T*>
 * member of a pointer to an object.
 *
 * A class template MyType was declared containing
 * a vector<T*> element.
 * The constructor push_back()'s value '10' to the
 * vector via a new and push_back call.
 * A pointer to MyType was declared in main().
 * Access to this first element was performed using
 * *(myType->myVec[0]).
 *
 * @file vectorOfPointerAccessExample.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

  
template<typename T>
class MyType
{
public:

  vector<T*> myVec;

  MyType()
  {
    T* tempT = new T;
    *tempT = 10;
    myVec.push_back(tempT);
  }

  ~MyType()
  {

    //destroy "new"d structures in vector
    for(typename vector<T*>::iterator iter = myVec.begin();
        iter!= myVec.end();
        ++iter)
    {
      delete *iter;
    }

    cout << "Destroying MyType" << endl;
  }



};

int main()
{
  typedef int T;
  MyType<T>* myType = new MyType<T>;


  //copy myType's vector first element
  T temp = (*(myType->myVec[0]));

  //should be 1
  cout << temp << endl;

  delete myType;

}
  
