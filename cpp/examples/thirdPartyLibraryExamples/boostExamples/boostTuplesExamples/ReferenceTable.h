/**
 * File implements a reference table used to check results for UWB System Model
 *
 * @file ReferenceTable.h
 */

#ifndef REFERENCETABLE_H
#define REFERENCETABLE_H
#include <iostream>
#include <boost/config.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <map>


enum KeyOneType {
  YES,
  NO 
};

enum KeyTwoType {
  MAYBE,
  ABSOLUTELY,
  KINDA
};

typedef boost::tuples::tuple<KeyOneType, KeyTwoType> TpKeyType;
typedef std::map<double,double> TpValueType;


class ReferenceTable
{
public:
  
  //populate reference MAP
  ReferenceTable();

  /**
   * Function returns a false if any value in the valueMap
   * is greater than the value in the valueMap of the referenceMap
   */
  bool tableCheck(std::map<TpKeyType, TpValueType>);

private:
  std::map<TpKeyType,TpValueType> refMap;

};
#endif
