/**
 * Example illustrates usage of a std::map with boost:tuple used for key
 * and value type
 *
 * @file anotherMapOfTuplesExample.cpp
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

using namespace std;
using namespace boost;

int main()
{

  typedef boost::tuples::tuple<string, string> TpValueType;
	std::map<std::string,TpValueType> testMap;
	
	string keyOne("keyOne");
	string keyTwo("keyTwo");
	string valueOneOne("valueOneOne");
	string valueOneTwo("valueOneTwo");
	string valueTwoOne("valueTwoOne");
	string valueTwoTwo("valueTwoTwo");
	TpValueType tupleOne = make_tuple(valueOneOne, valueOneTwo);
	TpValueType tupleTwo = make_tuple(valueTwoOne, valueTwoTwo);
	testMap.insert(make_pair(keyOne, tupleOne));
	testMap.insert(make_pair(keyTwo, tupleTwo));
	
	//extract
	cout << "KeyOneValueOne = " << testMap[keyOne].get<0>() << endl;
	cout << "KeyOneValueTwo = " << testMap[keyOne].get<1>() << endl;
	cout << "KeyTwoValueOne = " << testMap[keyOne].get<0>() << endl;
	cout << "KeyTwoValueTwo = " << testMap[keyOne].get<1>() << endl;

}

