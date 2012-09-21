/**
 * Example illustrates usage of boost::tuple
 *
 * @file butterflyExample.cpp
 */

#include <iostream>
#include <utility> //for pair
#include <complex>
#include <boost/config.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>


//templatized doButterfly function
template<typename T>
boost::tuple<T,T> doButterfly(const T& inA, const T& inB)
{
  return boost::make_tuple( (inA+inB), (inA-inB) );
}

int main()
{
  //create local complex variables used to drive butterfly function
  //and capture outputs
  std::complex<double> myCxA(1.0,2.0);
  std::complex<double> myCxB(3.0,5.0);
  std::complex<double> outCxA, outCxB;

  //print out inputs
  std::cout << "InA: " << myCxA << std::endl;
  std::cout << "InB: " << myCxB << std::endl;

  //call function, using boost::tie to extract tuple members
  boost::tie(outCxA, outCxB) = doButterfly(myCxA, myCxB);

  //print out results
  std::cout << "OutA: " << outCxA << std::endl;
  std::cout << "OutB: " << outCxB << std::endl;

}
