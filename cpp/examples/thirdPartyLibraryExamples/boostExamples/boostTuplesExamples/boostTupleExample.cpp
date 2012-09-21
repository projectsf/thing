/**
 * Example illustrates usage of boost::tuple
 *
 * @file boostTupleExample.cpp
 */

#include <iostream>
#include <utility> //for pair
#include <vector>
#include <boost/config.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <stdexcept>
#include <map>

using std::vector;
using boost::tuple;

template<
  typename T,
  typename TupleType
>
class TwoToOne
{
public:

  void makeVecOfTuples(vector<T>& inVec, vector<TupleType>& outVec) 
  {
    typename vector<TupleType>::iterator outIter = outVec.begin();

    for(typename vector<T>::iterator inIter = inVec.begin();
        inIter!=inVec.end();
        ++inIter, ++outIter)
    {
      //grab length of templated tuple
      unsigned int tupleLength = boost::tuples::length<TupleType>::value;

      //create vector 
      vector<T> tempVec;

      //populate temp vector to hold variables
      //of tuple

      //push_back current value
      tempVec.push_back(*inIter);

      //push_back additional values
      for(unsigned int ii=1;ii<tupleLength;++ii)
      {
        ++inIter;
        tempVec.push_back(*inIter);
      }

      //has to be hardcoded at this point
      switch (tupleLength)
      {
        case(2) :
        {
          *outIter = boost::make_tuple(tempVec.at(0), tempVec.at(1));
          break;
        }

        default:
        {
          throw std::logic_error("Undefined type in makeVecOfTuples case statement");
          break;
        }
      }//switch statement
    }
    
  }//makeVecOfTuples

  //vecOfTuples.size() = outVec.size()
  void mapTuplesToScalars(vector<TupleType>& vecOfTuples, vector<T>& outVec, std::map<TupleType,T>& mapScheme)
  {

    typename vector<T>::iterator outIter = outVec.begin();
    for(typename vector<TupleType>::iterator iter = vecOfTuples.begin();
        iter!= vecOfTuples.end();
        ++iter, ++outIter)
    {
      *outIter = mapScheme[(*iter)];
    }
  }


private:
 
};

int main()
{

  typedef int T;
  typedef boost::tuples::tuple<T,T> keyType;
  typedef T valueType;
  //configure size of vectors
  const size_t sizeInVec = 10;
  const size_t sizeOutVec = sizeInVec/2;

  //init vectors
  vector<T> inVec(sizeInVec);
  vector<boost::tuple<T,T> > tupleVec(sizeOutVec);
  vector<T> outVec(sizeOutVec);

  //define class TwoToOne
  TwoToOne<T,boost::tuple<T,T> > twoToOne;

  //populate inVec with all 2's
  std::fill(inVec.begin(), inVec.end(), 2);

  //create a map that maps 2 to 4
  std::map<keyType,valueType> myMap;
  myMap[boost::make_tuple(2,2)] = 4;

  //map inVec to outVec
  try  
  {
    twoToOne.makeVecOfTuples(inVec, tupleVec);
    twoToOne.mapTuplesToScalars(tupleVec,outVec,myMap);
  }

  catch(std::exception& exc)
  {
    std::cout << exc.what() << '\n';
  }

  //print out inVec
  std::cout << "inVec = " << '\n';
  for(vector<T>::iterator iter = inVec.begin();
      iter!= inVec.end();
      ++iter)
  {
    std::cout << *iter << '\n';
  }
  
  //print out outVec
  std::cout << "tupleVec = " << '\n' ;
  for(vector<boost::tuple<T,T> >::iterator iter = tupleVec.begin();
      iter!= tupleVec.end();
      ++iter)
  {
    std::cout << (*iter) << '\n';
  }
  
  //print out outVec
  std::cout << "outVec = " << '\n' ;
  for(vector<T>::iterator iter = outVec.begin();
      iter!= outVec.end();
      ++iter)
  {
    std::cout << *iter << '\n';
  }
  
  
}
