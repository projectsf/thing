/**
 * Example investigates boost::any class
 *
 * Boost::any can be put into a vector, which gets around C++
 * strict homogenous vector requirement
 *
 * @file boostAny.cpp
 */

#include <iostream>
#include <boost/config.hpp>
#include <boost/any.hpp>
#include <vector>
#include <complex>


class Writer
{
public:
  Writer(int number)
    : myNumber(number)
  {}

  void operator()() const
  {
    this->writeMe();
  }

  void writeMe() const
  {
    std::cout << "Class Writer has this number = " << this->myNumber << '\n'; 
  }

private:
  int myNumber;
};

int main()
{

  //define a vector of any
  std::vector<boost::any> myVec;

  //create 5 diffent types to push to vector
  int myInt = 3;
  std::string myString("hello");
  double myDouble = 5.6;
  std::complex<double> myComplex(2.0,3.5);
  Writer myWriter(40);
  


  myVec.push_back(myInt);
  myVec.push_back(myString);
  myVec.push_back(myDouble);
  myVec.push_back(myComplex);
  myVec.push_back(myWriter);


  std::vector<boost::any>::iterator iter = myVec.begin();


  try
  {
    std::cout << "first value = " <<  boost::any_cast<int>(*iter) << "\n";
  }

  catch(boost::bad_any_cast& e)
  {
    std::cout << "Bad cast from any to int" << "\n";
  }

  //increment iterator
  ++iter;

  try
  {
  std::cout << "second value = " <<  boost::any_cast<std::string>(*iter) << "\n";
  }

  catch(boost::bad_any_cast& e)
  {
    std::cout << "Bad cast from any to string" << "\n";
  }

  //increment iterator 
  ++iter;

  try
  {
    std::cout << "third value = " <<  boost::any_cast<double>(*iter) << "\n";
  }

  catch(boost::bad_any_cast& e)
  {
    std::cout << "Bad cast from any to double" << "\n";
  }

  //increment iterator 
  ++iter;

  try
  {
    std::cout << "fourth value = " <<  boost::any_cast<std::complex<double> >(*iter) << "\n";
  }

  catch(boost::bad_any_cast& e)
  {
    std::cout << "Bad cast from any to complex<double>" << "\n";
  }

  //increment iterator 
  ++iter;

  try
  {
    Writer newWriter = boost::any_cast<Writer>(*iter); 
    newWriter();
  }

  catch(boost::bad_any_cast& e)
  {
    std::cout << "Bad cast from any to class Writer" << "\n";
  }

}
