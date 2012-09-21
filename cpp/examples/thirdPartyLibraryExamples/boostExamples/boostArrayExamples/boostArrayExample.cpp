/**
 * Illustrates the use of boost::array
 *
 * @file boostArrayExample.cpp
 */


#include <iostream>
#include <boost/array.hpp>
#include <string>

using namespace boost;

int main()
{
	//initialize 3 values, last one is default initialized
	array<int,4> initializedValues = { { 1, 2, 3 } };

	//don't initialize any and all are undefinied
	array<int,4> uninitializedValues;


	for (array<int,4>::iterator iter = initializedValues.begin(); iter != initializedValues.end(); ++iter)
	{
    	std::cout << *iter <<std::endl;
	}

	for (array<int,4>::iterator iter = uninitializedValues.begin(); iter != uninitializedValues.end(); ++iter)
	{
    	std::cout << *iter <<std::endl;
	}
}

