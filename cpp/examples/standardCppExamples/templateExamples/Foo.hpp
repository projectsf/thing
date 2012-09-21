#include <iostream>
using namespace std;

class Foo
{
  public:
    template<typename T> T foo(T dummy);
		template<typename T> void foo(int dummy1, int dummy2);
};

template<typename T> T Foo::foo(T dummy) 
{
	T value = 8;
	cout << "Base" << endl; 
	return value; 
}

template<typename T> void Foo::foo(int dummy1, int dummy2) 
{
	cout << "Base with two dummy args" << endl; 
}
