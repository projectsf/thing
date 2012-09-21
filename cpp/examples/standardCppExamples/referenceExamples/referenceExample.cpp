/**
 * Example looks at vectors and references to vectors
 *
 * Interested in the following:
 * <ul>
 * <li> What happens when you copy a vector to a reference to a vector
 * <li> How do you initialize a reference to a vector
 * <li> What happens when you call vector member functions using the
 * references
 * </ul>
 *
 * Learned:
 * <ul>
 * <li> A reference must be initialized to point to an object.  It can't
 * be assigned to point to another object
 * </ul>
 *
 * @file referenceExample.cpp
 */

#include <iostream>
#include <vector>

template<typename T>
void checkRef(std::vector<T>& vecA, std::vector<T>& vecB)
{
  if( vecA.begin() != vecB.begin() )
    std::cout << "Different begins. " << std::endl;
}

int main()
{
  typedef int T;
  const unsigned int SIZE = 1;
  const unsigned int NUM_ITERATIONS = 1000000;
  std::vector<T> aVec(SIZE);
  std::vector<T>& vecRef = aVec;

  for(unsigned int ii=1; ii< NUM_ITERATIONS; ++ii) {
    aVec.resize(SIZE*2*ii);
    checkRef(aVec, vecRef);
  }

}
  

