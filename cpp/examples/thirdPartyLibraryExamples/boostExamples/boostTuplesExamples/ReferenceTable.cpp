/**
 * Implementation file for ReferenceTable.h
 *
 * @file ReferenceTable.cpp
 */

#include "ReferenceTable.h"


ReferenceTable::ReferenceTable()
{
  {
    TpKeyType mapKey = boost::make_tuple(YES, MAYBE);
    std::map<double,double> refValueMap;
    refValueMap[5.0] = 0.1;
    refValueMap[-2.0] = 0.01;
    refValueMap[-1.0] = 0.1;
    refMap[mapKey] = refValueMap;
  }

  {
    TpKeyType mapKey = boost::make_tuple(NO, ABSOLUTELY);
    std::map<double,double> refValueMap;
    refValueMap[5.0] = 0.1;
    refValueMap[-2.0] = 0.01;
    refValueMap[-1.0] = 0.1;
    refMap[mapKey] = refValueMap;
  }

}


bool ReferenceTable::tableCheck(std::map<TpKeyType, TpValueType> testMap)
{
  bool returnValue = true;
  for(std::map<TpKeyType, TpValueType>::iterator testMapIter = testMap.begin();
      testMapIter != testMap.end();
      ++testMapIter)
  {
    KeyOneType tempKeyOne;
    KeyTwoType tempKeyTwo;
    boost::tie(tempKeyOne,tempKeyTwo) = testMapIter->first;
    std::cout << "*************************************************************" << std::endl;
    std::cout << "* Checking test table for keys = " << tempKeyOne << " and: " << tempKeyTwo << std::endl;
    std::cout << "*************************************************************" << std::endl;
    for(std::map<double,double>::iterator testMapValueIter = (testMapIter->second).begin();
        testMapValueIter != (testMapIter->second).end();
        ++testMapValueIter)
    {
      double snrValue = testMapValueIter->first;
      std::cout << "Checking test cell against reference."  << std::endl <<  "  TEST:      snr = " << testMapValueIter->first << ", per = " << testMapValueIter->second << std::endl;

      //reset reference iterator
      std::map<double,double>::iterator refValueMapIter = refMap[testMapIter->first].begin();

      //find snrValue in reference MAP
      while ((refValueMapIter->first < snrValue) && ((++refValueMapIter) != refMap[testMapIter->first].end()) );

      if(refValueMapIter == refMap[testMapIter->first].end())
        --refValueMapIter;

      std::cout << "  REFERENCE: snr = " << refValueMapIter->first << ", per = " << refValueMapIter->second << std::endl;

      if (testMapValueIter->second <= refValueMapIter->second)
        std::cout << "Test Passed for case: " <<  testMapValueIter->first << std::endl << std::endl;
      else {
        returnValue = false;
        std::cout << "Test failed for case: " << testMapValueIter->first << std::endl;
        std::cout << "Test value: " << testMapValueIter->second << " is greater than reference value: " << refValueMapIter->second << std::endl << std::endl;
      }
    }
  }
  return returnValue;
}
