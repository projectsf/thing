/**
 * Illustrates the use of boost weak pointers
 *
 *
 * @file boostWeakPointerExample.cpp
 */

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost;

class Shape
{
	public:
		Shape(const string& name) : name(name)
		{
		}
		const string& getName() const
		{
			return name;
		}
		~Shape() 
		{ 
			std::cout << "Destroying .." << std::endl; 
		}
  
	private:
		string name;
};


int main()
{
	boost::shared_ptr<Shape> strongShape(new Shape("shape"));
	boost::weak_ptr<Shape> weakShape(strongShape);

	strongShape.reset();
	cout << "reset strong" << endl;

	//try to make strong
	shared_ptr<Shape> shape = weakShape.lock();

	if (shape)
	{
		cout << shape->getName() << endl;
	}
}



