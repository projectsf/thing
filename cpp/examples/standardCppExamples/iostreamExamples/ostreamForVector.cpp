/**
 * Example overloads operator<< to support std::vector<T>
 *
 * @file ostreamForVector.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
  if(vec.size() <= 0)
  {
    std::string errorMessage = "vector size for operator<<(ostream& os, const std::vector<T>& vec) is of size =" "\n" ;
    throw std::logic_error(errorMessage);
    return os;
  }

  else
  {
    os << "[";
    typename std::vector<T>::const_iterator endMinusOne = vec.end()-1;
    for(typename std::vector<T>::const_iterator iter = vec.begin();
        iter!=endMinusOne;
        ++iter)
    {
      os << *iter << ", ";
    }

    //capture last element but don't append comma
    os << *endMinusOne;

    //append closing bracket
    os << "] " << '\n';
  }

  return os;
}

int main() 
{
  size_t vecSize = 10;
  std::vector<int> myVec;

  for(unsigned int ii=0;ii<vecSize;++ii)
  {
    myVec.push_back(ii);
  }

  std::cout << myVec << std::endl;
}
