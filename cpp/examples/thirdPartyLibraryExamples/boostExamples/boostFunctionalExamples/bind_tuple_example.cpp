/**
 * Example illustrates how to use some of Boost's features
 * that are going to be part of TR1
 *
 * Features included:
 * <ul>
 * <li> Tuple
 * <li> Tie
 * <li> Bind
 * Bind must use variables.  Simple putting in 1 for an unsigned int argument
 * doesn't seem to work.  <br>
 * If all function arguments are bound, the () must still follow the bind call
 * <li> Function
 * </ul>
 *
 * @file bind_tuple_example.cpp
 */

#include <iostream>
#include <vector>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

boost::tuple<double,double> tupleSwap(double a, double b, int doSwap)
{
  if (doSwap) 
    return boost::make_tuple<double,double>(b,a);
  else
    return boost::make_tuple<double,double>(a,b);
}

double addThese(double a, double b, double c)
{
  return a+b+c;
}



int main()
{
  const unsigned int NUM_ITERATIONS = 10;
  typedef boost::function<boost::tuple<double,double>(double,double,int)> TpFunc;
  std::vector<TpFunc> functionVec;
  std::vector<double> functionArgs;

  std::cout << "A call to addThese binded with (1,2,3)" << std::endl;
  double temp = boost::bind(addThese,1.0,2.0,3.0)();
  std::cout << "Result: " << temp << std::endl;

  for(unsigned int ii = 0; ii<NUM_ITERATIONS; ++ii) {
    functionArgs.push_back(static_cast<double>(ii));
  }

  for(unsigned int ii = 0; ii<NUM_ITERATIONS/2; ++ii) {
    functionVec.push_back( &tupleSwap );
  }
  
  for(unsigned int ii = 0; ii<NUM_ITERATIONS/2; ++ii) {
    functionVec.push_back( &tupleSwap );
  }

  //loop calls iterates through function vector calling function
  //at each iteration.
  //boost::bind binds 1 to toSwap argument in first half
  //and 0 to toSwap argument of second half
  unsigned int ii = 0;
  std::vector<double>::iterator argIter = functionArgs.begin();
  for(std::vector<TpFunc>::iterator funcIter = functionVec.begin();
      funcIter!=functionVec.end();
      ++funcIter, ++argIter, ++ii)
  {
    double retA, retB;

    if( ii < 5 ) {
      //boost::tie(retA, retB) = boost::bind( (*funcIter),_3, 1)(*argIter, *argIter-1.0);
      unsigned int toSwap = 1;
      boost::tie(retA, retB) = boost::bind(*funcIter,*argIter, *argIter-1.0,_1)(toSwap);
    }
    else {
      unsigned int toSwap = 0;
      boost::tie(retA, retB) = boost::bind(*funcIter,*argIter, *argIter-1.0,_1)(toSwap);
      //boost::tie(retA, retB) = boost::bind( (*funcIter),_3, 0)(*argIter, *argIter-1.0);
    }
    
    std::cout << "Passed in: " << *argIter << " " << (*argIter-1.0) << std::endl;
    std::cout << "Returned : " << retA << " " << retB << std::endl;
  }
        

  

  

  


}
