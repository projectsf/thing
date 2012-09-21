/**
 * Example illustrates use of MATLAB mex interface to read
 * MATLAB cells
 *
 *
 * @file readingMatlabCellsExample.cpp
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
  std::vector<double> myVec;
  std::string fileName("./matlab/cellDump.mat");
  std::string cellName("perCurve");
  std::string fieldName("SNR");

  MatlabInterface myMat;
  myMat.open(fileName);

  try {
    std::string fullName = cellName + "." + fieldName;
    myMat.copy(fullName,myVec);
  }
  catch(std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
    throw;
  }

  //print out results
  std::cout << "myVec contents: " << std::endl;
  std::for_each( myVec.begin(), myVec.end(), PrintFunctor() );
 
}
