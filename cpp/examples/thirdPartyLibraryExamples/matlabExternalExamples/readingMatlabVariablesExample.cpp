/**
 * Example illustrates use of MATLAB mex interface using
 * MatlabInterface class created in the utilities directory
 *
 * Goal is to create one routine that can be used for the
 * following situations:
 * <ul>
 * <li> Copying the contents of a MATLAB variable with name <variableName>
 * and type T into a std::vector<T>
 * The following types (T) need to be supported
 * <ul>
 * <li> double, complex<double> vector<complex<double> >
 * </ul>
 * </ul>
 *
 * @file readingMatlabVariablesExample.cpp
 */

/**
 * @warning systemc.h must be included before mat.h
 */
#include "systemc.h"
#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include "mat.h"
#include <stdexcept>
#include "utilities/MatlabInterface.hpp"

struct PrintFunctor
{
  template<class T>
  void operator()(T in)
  {
    std::cout << in << std::endl;
  }

  template<class T>
  void operator()(std::vector<T> in)
  {
    for_each( in.begin(), in.end(), PrintFunctor() );
  }

};

int main()
{
  typedef std::vector<double> TpOneDimType;
  typedef std::vector<std::vector<double> > TpTwoDimType;
  TpOneDimType oneDimVec;
  TpTwoDimType twoDimVec;
  std::string fileName("./matlab/dump.mat");
  std::string oneDimName("oneDimStructure.oneDim");
  std::string twoDimName("twoDimStructure.twoDim");

  MatlabInterface myMat;
  myMat.open(fileName);

  try {
    myMat.copy(oneDimName,oneDimVec);
    myMat.copy(twoDimName,twoDimVec);
  }
  catch(std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
    throw;
  }

  //print out results
  std::cout << "One Dimensional results: " << std::endl;
  std::for_each( oneDimVec.begin(), oneDimVec.end(), PrintFunctor() );

  std::cout << "Two Dimensional results: " << std::endl;
  std::for_each( twoDimVec.begin(), twoDimVec.end(), PrintFunctor() );

  
}
