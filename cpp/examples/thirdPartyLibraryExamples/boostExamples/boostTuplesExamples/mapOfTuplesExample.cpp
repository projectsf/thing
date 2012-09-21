/**
 * Example illustrates usage of a std::map with boost:tuple used for key
 * and value type
 *
 * @file mapOfTuplesExample.cpp
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
#include "ReferenceTable.h"

int main()
{

  typedef boost::tuples::tuple<KeyOneType, KeyTwoType> TpKeyType;
  typedef std::map<double,double> TpValueType;
  std::map<TpKeyType,TpValueType> testMap;


  //create reference table
  ReferenceTable referenceTable;

  //populate test data structures
  {
    std::map<double,double> testValueMap;
    testValueMap[-2.0] = 0.1;
    testValueMap[1.0] = 0.1;
    testValueMap[-9.0] = 0.1;
    testValueMap[-1.6] = 0.01;
    testValueMap[3.0] = 0.01;
    testValueMap[6.0] = 0.01;
    testValueMap[0.0] = 0.01;
    KeyOneType testKeyOne = YES;
    KeyTwoType testKeyTwo = MAYBE;
    TpKeyType testMapKey = boost::make_tuple(testKeyOne,testKeyTwo);
    testMap[testMapKey] = testValueMap;
  }

  {
    std::map<double,double> testValueMap;
    testValueMap[-2.0] = 0.0011;
    testValueMap[1.0] = 0.0001;
    testValueMap[-9.0] = 0.0001;
    testValueMap[-1.6] = 0.1;
    testValueMap[3.0] = 0.00001;
    testValueMap[6.0] = 0.00001;
    testValueMap[0.0] = 0.00001;
    KeyOneType testKeyOne = NO;
    KeyTwoType testKeyTwo = ABSOLUTELY;
    TpKeyType testMapKey = boost::make_tuple(testKeyOne,testKeyTwo);
    testMap[testMapKey] = testValueMap;
  }

 
  //check testTable vs ReferenceTable
  if(referenceTable.tableCheck(testMap))
    std::cout << "Check passed" << std::endl;
  else
    std::cout << "Check failed" << std::endl;

}

