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

#include <string>
#include <iostream>
#include <set>

using namespace std;


template <typename T>
class Shape 
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
	
	void deleteMyself(set<Shape<int>* >& aSet) 
	{
		aSet.erase(this);
    cout << "Me: " << this->getName() << " is still in here" << endl;
    
	}

  ~Shape() {cout << "Destroyed shape" << endl; }
		
  
private:
  std::string m_name;
};




int main()
{
	set<Shape<int>* > aSet;

  if(true)
  {
	  Shape<int>* pShape = new Shape<int>("A shape");
    aSet.insert(pShape);
    cout << "Set size: " << aSet.size() << endl;
  }

  (*(aSet.begin()))->deleteMyself(aSet);

  cout << "Set size after remove: " << aSet.size() << endl;
	
}




