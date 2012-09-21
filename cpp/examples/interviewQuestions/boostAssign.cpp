#include <vector>
#include <iostream>
#include "boost/assign/list_of.hpp"



int main()
{
  const std::vector<unsigned int> vUint = boost::assign::list_of<unsigned int>(0)(1)(1)(0)(1);
  
  for(std::vector<unsigned int>::const_iterator iter = vUint.begin();
      iter != vUint.end();
      ++iter)
  {
  	std::cout << "Element value: " << *iter << std::endl;
  }

}
