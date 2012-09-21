/**
 * Example illustrates the handle/body idiom for function
 * objects.
 * 
 * Lessons learned:
 * <ul>
 * <li> Handle/body idiom is useful with STL and BOOST 
 * constructs that use function objects.  Often these function
 * objects are copied and put into containers.  Handle/body
 * with boost::shared_ptr is a good way to address this.
 * <ul>
 * <li> Handle/body idiom allows you to put a sizeable implementation
 * into one class.  This implementation is only "pointed to" by
 * the function object.  shared_ptrs insure that there is only
 * one implementation object and that's it properly deleted
 * when it is no longer referenced.
 * <li> shared_ptr is reference counted so it is perfect for 
 * containers.
 * </ul>
 * </ul>
 * Questions:
 * <ul>
 * <li> If I have a vector of function objects, how do I call 
 * operator() for each unique function object in a for_each.
 * <li> How do I use const to insure that the handle doesn't
 * modify the implementation
 * </ul>
 */
 
 #include <iostream>
#include <vector>
#include "boost/shared_ptr.hpp"
#include "boost/mem_fn.hpp"

struct FuncImpl
{
	FuncImpl(std::string name)
	  : m_name(name)
	{}
	
	template<typename T>
	void operator()(T in) const
	{
		std::cout << in << m_name << std::endl;
	}
	
	void appendToName(std::string app) const
	{
		m_name += app;
	}
	
	void printString() const
	{
		std::cout <<  m_name << std::endl;
	}
	~FuncImpl()
	{
		std::cout << "Destroying FuncImpl" << std::endl;
	}
	
private:
  mutable std::string m_name;
};

struct Func
{
	Func(const boost::shared_ptr<FuncImpl> pImpl)
	  : m_pImpl(pImpl)
	{
	  std::cout << "Use count = " << m_pImpl.use_count() << std::endl;
	}
	
	template<typename T>
	void operator()(T in)
	{
		m_pImpl->appendToName("r");
		(*m_pImpl)(in);
	}
	
	void printString()
	{
		m_pImpl->printString();
	}
	
	~Func()
	{
		std::cout << "Destroying Func" << std::endl;
	}
	
	
	
private:
  boost::shared_ptr<FuncImpl> m_pImpl;
};

int main()
{
  std::vector<Func> sVec;
  sVec.reserve(5);
  
  std::cout << "Constructing sharePtr" << std::endl;
  boost::shared_ptr<FuncImpl> sharePtr(new FuncImpl("Mi.."));
  
  std::cout << "In push_back" << std::endl;
  sVec.push_back(sharePtr);
  sVec.push_back(sharePtr);
  sVec.push_back(sharePtr);
  sVec.push_back(sharePtr);
  sVec.push_back(sharePtr);
  
  std::cout << "In for_each" << std::endl;
  std::for_each(sVec.begin(), sVec.end(), boost::mem_fn(&Func::printString) );
  
  std::cout << "Ending Application" << std::endl;
  
  }
