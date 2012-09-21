/** Example creates a vector<vector<T>* > and destroys "new'd" objects by
 * iterating through it and calling delete on each element
 *
 * @file destroyingVecOfPointers.cpp
 */

#include <iostream>
#include <vector>
#include <string>


class Class
{
public:
  Class() 
    : size(3)
  {
    for(unsigned int ii=0;ii<size;++ii)
    {
      myVec.push_back(new std::string("whatever"));
    }
  }

  virtual ~Class()
  {
    std::cout << "In Class  Destructor" << std::endl;
    for(std::vector<std::string*>::iterator iter = myVec.begin();
        iter!=myVec.end();
        ++iter)
    {
      std::cout << "Deleting element: " << *iter << "in this: " << this << std::endl;
      delete *iter;
    }
  }

protected:
  std::vector<std::string*> myVec;
  std::vector<int> myVecOfInt;
  unsigned int size;

};

class deriv1 : public Class
{
public:
  ~deriv1()
  { 
    std::cout << "In deriv1 destructor" << std::endl;
  }

  std::vector<int> myInt;
};

class deriv2 : public Class
{
public:
  ~deriv2()
  { 
    std::cout << "In deriv2 destructor" << std::endl;
  }

  
};

class BigClass 
{
public:
  BigClass()
  {
    pDeriv1 = new deriv1;
    pDeriv2 = new deriv2;
  }

  ~BigClass()
  {
    std::cout << "In Big class destructor" << std::endl;
    delete pDeriv1;
    delete pDeriv2;
  }


  deriv1* pDeriv1;
  deriv2* pDeriv2;
};

int main()
{


  {
    BigClass myBigClass;
  }
 
}
