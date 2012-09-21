/**
 * Example illustrates use of std::mem_fun_ref and std::mem_fun
 * and boost::mem_fn.  It also illustrates use of ordered container
 * and what's required to use one
 *
 * Lessons Learned:
 * <ul>
 * <li> "bool operator<(const ClassName& rhs)" must be implemented for any class
 * that will go into an ordered container.
 * <li> std::mem_fun is used to adapt a pointer to a member function to a function
 * object, so you can you use STL algorithms
 * <li> std::mem_fun_ref is used to adapt an object or a reference to a object member
 * function to a function object
 * <li> boost::mem_fn can be used to adapt a reference, pointer or shared_ptr to a
 * function object
 * </ul>
 *
 * @file mem_fn_example.cpp
 */
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;

class Element
{
public:
	
	Element(std::string name)
	  : m_name(name)
	{}
	
	std::string getName() const
	{
		return m_name;
	}
	
	void printName() const
	{
		std::cout << m_name << std::endl;
	}
	
	bool operator<(const Element& e) const
	{
		return m_name < e.getName();
	}

  void printNameAndMore(std::string inString)
  {
    std::cout << m_name << " " << inString << std::endl;
  }
	
private:
  std::string m_name;
};


int main()
{
	Element e1("e1"), e2("e2");
	std::set<Element> mySet;
	std::set<Element*> mySetOfP;
	
	mySet.insert(e2);
	mySet.insert(e1);
	
	mySetOfP.insert(new Element("element two"));
	mySetOfP.insert(new Element("element one"));

  //mem_fun_ref is used if you have an object or an object reference.
  //mySet constains objects in this case
	for_each(mySet.begin(), mySet.end(), std::mem_fun_ref(&Element::printName) );

  //mem_fun_ref is used if you have a pointer to an object
  //mySetOfP contains pointers in this case
	for_each(mySetOfP.begin(), mySetOfP.end(), std::mem_fun(&Element::printName) );

  //we can use boost::mem_fn for both std::mem_fun and std::mem_fun_ref cases
  for_each(mySet.begin(), mySet.end(), boost::mem_fn(&Element::printName) );
  for_each(mySetOfP.begin(), mySetOfP.end(), boost::mem_fn(&Element::printName) );

  std::string tempString("and more");
  // the "_1" is needed because of the implicit this parameter
  for_each(mySetOfP.begin(), mySetOfP.end(), boost::bind(&Element::printNameAndMore, _1, tempString) );
  
}
