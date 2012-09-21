#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost;


shared_ptr<int> foo(shared_ptr<int> ptr)
{
	cout << ptr.get() << endl;
  *ptr = 4;
  return ptr;
}

int main()
{
	shared_ptr<int> ptr(new int(3));
  cout << ptr.get() << endl;

  shared_ptr<int> ptr2 = foo(ptr);


  cout << ptr.get() << endl;
	
}
