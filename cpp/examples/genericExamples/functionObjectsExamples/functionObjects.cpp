/**
 * Example illustrates use of Function Objects with std::for_each
 * 
 * Lessons Learned:
 * <ul>
 * <li> Function object must be followed by () in call in for_each.
 * <li> Unary function objects should derive from std::binary_function
 * to insure that its adaptable by other function adapters in STL
 * <li> To use a member function of a class template, the type must be included
 * , i.e. mem_fun(&Element<string>::printName)
 * <li> for_each(first, last, F), returns F, so it can be nested.  
 * I can't figure out how to pass the elements traversed in first for_each
 * to the second one, though.
 * </ul>
 * 
 * @file functionObjects.cpp
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

/**
 * Class used for Function Object Example
 */
template<typename T>
class Element
{
public:
	
	Element(T name)
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
	
private:
  T m_name;
};

/**
 * Class inherits from std::unary_function to insure that its adaptable
 */
class PrintFunctor : public std::unary_function< vector<Element<string>* >, bool>
{
public:
	void operator()(const vector<Element<string>* >& vec) const
	{
		for_each( vec.begin(), vec.end(), mem_fun(&Element<string>::printName) );
	}
};

int main()
{
  vector<vector<Element<string>* > > myVec;
	vector<Element<string>* > tempVec;
	tempVec.push_back(new Element<string>("e1"));
	tempVec.push_back(new Element<string>("e2"));
	myVec.push_back(tempVec);
	
	//for_each with PrintFunctor function object
	for_each(myVec.begin(), myVec.end(), PrintFunctor() );
	
	//nested for_each
	for_each(myVec.begin(), myVec.end(), 
		for_each(myVec.begin(), myVec.end(), PrintFunctor() ) );
  
}