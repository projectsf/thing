#include "Foo.hpp"

template<> int Foo::foo(int dummy) 
{
	int myInt = 3;
	cout << "Specialized" << endl; 
	return myInt; 
}

template<> void Foo::foo(int dummy1, int dummy2) 
{
	int myInt = 3;
	cout << "Specialized with two dummy vars" << endl; 
}
