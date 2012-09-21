/** Code looks at generic function transform
 *
 * Lessons learned:
 * <ul>
 * <li> std::transform can be used to copy the sum
 * of vectors A and B to vector B by way of
 * std::plus<T> binary operator
 * </ul>
 *
 * @file transformExample.cpp
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace util{
  template<typename T>
  void printVector(const std::vector<T>& vec, const std::string& vectorName)
  {
    std::cout << "Vector: " << vectorName << std::endl;
    
    for(typename vector<T>::const_iterator iter = vec.begin();
        iter!= vec.end();
        ++iter)
    {
      std::cout << *iter << std::endl;
    }
  }
}


int main()
{
  const unsigned int VEC_SIZE = 3;
  vector<double> vecA(VEC_SIZE), vecB(VEC_SIZE);

  vecA[0] = 1.0;
  vecA[1] = 2.0;
  vecA[2] = 3.0;
  
  vecB[0] = 1.0;
  vecB[1] = 2.0;
  vecB[2] = 3.0;

  util::printVector(vecB, "vecB");

  std::transform( vecA.begin(), vecA.end(), vecB.begin(), vecB.begin(), std::plus<double>() );

  util::printVector(vecB, "vecB");


}
