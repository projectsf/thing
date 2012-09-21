/**
 * Example looks at member template functions
 *
 * @file memberTemplateFunctionExample.cpp
 */

#include <iostream>

template<typename T>
T returnMeToo()
{
  T temp;
  return temp;
}

class ReturnMe;

template<typename T>
class Class
{

public:
  Class()
  {
    returnMe = new ReturnMe;
    //returnMe = new ReturnMe<unsigned int>;
  }

  ~Class()
  {
    delete returnMe;
  }

  void run()
  {
    unsigned int paramTemp;
    //std::cout << returnMe->returnMe(paramTemp) << std::endl;
    std::cout << returnMe->returnMe(paramTemp) << std::endl;
    //std::cout << returnMe->returnMe() << std::endl;
    //std::cout << ::returnMeToo<double>() << std::endl;
  }

private:
  ReturnMe* returnMe;
  //ReturnMe<unsigned int>* returnMe;
  double myDouble;
  
  
};


//template<typename T>
class ReturnMe
{

public:
  template<typename FT>
  FT returnMe(FT = 0)
  {
    FT temp;
    return temp;
  }
};

int main()
{

  Class<int> myClass;
  //Class myClass;

  myClass.run();

}
