/**
 * Illustrates the use of boost shared pointers
 *
 * How to downcast when using shared_ptrs
 *
 * @file sharedPointerDowncastExample.cpp
 */

#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>


using namespace std;
using namespace boost;

class Foo
{
	public:
	
		Foo(const string& name) :
		name(name)
		{
			cout << "Constructing Foo .." << endl; 
		}
	
		virtual ~Foo() 
		{ 
			cout << "Destroying Foo .." << endl; 
		}

		virtual string getName() const
		{
			return name;
		}
  
	protected:
		string name;
};

class Bar : public Foo
{
	public:
	
		Bar(const string& name) :
		Foo(name)
		{
			cout << "Constructing Bar .." << endl; 
		}

		virtual string getName() const
		{
			return name;
		}

		virtual ~Bar() 
		{ 
			cout << "Destroying Bar .." << endl; 
		}
};


int main()
{
	shared_ptr<Foo> foo(new Bar("foo"));
	shared_ptr<Bar> bar = shared_dynamic_cast<Bar>(foo);

	cout << bar->getName() << endl;
	
}



