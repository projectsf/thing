/**
 * Illustrates the use of boost shared pointers
 *
 * Illustrate how const w/shared pointer differs
 * from const with raw pointers
 *
 * @file sharedPointerDowncastExample.cpp
 */

#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>


using namespace std;
using namespace boost;

void foo(shared_ptr<const int> value)
{
	*value = 3;
}


int main()
{
	shared_ptr<int> value(new int(3));
	foo(value);
}



