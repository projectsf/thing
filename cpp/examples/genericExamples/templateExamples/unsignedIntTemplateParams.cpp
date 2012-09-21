/**
 * Example creates a class that uses an unsigned int Template parameter
 * to initialize a vector
 *
 * @file unsignedIntTemplateParams.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

  
template<typename T,int numT = 1>
class MyType 
{
public:

  MyType() :
    myVecOfT()
  {
    for(unsigned int ii=1;ii<=numT;++ii)
    {
      myVecOfT.push_back(ii);
    }
  }
    
  const vector<T>& getVecOfT()
  {
    return myVecOfT;
  }

  ~MyType()
  {
    cout << "Destroying MyType" << endl;
  }

private:
  vector<T> myVecOfT;

};

int main()
{

  typedef unsigned int T;
  //create a class with a vector<int> of size = 2
  MyType<T,2> myType;

  //get vector
  const vector<T> newVec = myType.getVecOfT();

  //print out vector
  for(vector<T>::const_iterator iter = newVec.begin();
      iter!= newVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }


}
  
  


  

  

