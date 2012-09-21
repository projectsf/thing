/**
 * Illustrates the use of enable_shared_from_this
 *
 * How to use enable_shared_from_this in class templates
 * 
 * I didn't know that the "this" was required in
 * this->shared_from_this() on line 43.
 *
 * @file enableSharedFromThis.cpp
 */

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include <iostream>


using namespace std;
using namespace boost;


template <typename T>
class Shape : public enable_shared_from_this<Shape<T> >
{
public:
  Shape(const std::string& name)
  : m_name(name)
  {}
  ~Shape() {}
	
	string getName() const
	{
		return m_name;
	}
	
	void subscribe(boost::shared_ptr<Shape<T> > pShape)
	{
		cout << "Subscribing " << pShape->getName() << endl;
	}
	
	void subscribe() 
	{
		subscribe(this->shared_from_this());
	}
		
  
private:
  std::string m_name;
};




int main()
{
	boost::shared_ptr<Shape<int> > pShape(new Shape<int>("A shape"));
	
	pShape->subscribe();
}




