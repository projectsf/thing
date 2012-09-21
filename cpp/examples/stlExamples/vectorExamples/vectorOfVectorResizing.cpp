/**
 * Code analyzes how resizes function
 * for vectors of vectors.
 *
 * Code investigated how capacity()
 * and size() are affected by resizes
 * for vector of vectors.
 *
 * Lessons learned:
 * <ul> 
 * <li> The first constructor argument in a
 * vector of vectors sizes the outer vectors
 * <li> Multiple dimension vectors support
 * multiple arguments in the constructor. <br>
 * Each argument sizes the vector that dimension.
 * <br>
 * In this case, the second argument sizes
 * the 2nd dimension (inner) vector.
 * <li> An inner vector can be resized through
 * a resize() call on that inner vector. <br>
 * This example dereferences an iterator returned
 * by a begin() call on the outer vector
 * <li> A clear() on a vector of vectors
 * sets size and capacity to 0 for the
 * vector of vectors.<br>
 *
 * @file vectorOfVectorResizing.cpp
 */

#include <iostream>
#include <vector>

/**
 * Prints out size and capacity info for vector of vectors
 *
 * Prints out both inner and outer vector size
 * and capacity information
 */
template<typename T>
void printInfo(std::vector<std::vector<T> > inVec)
{
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << " Printing info: " <<  std::endl;
  std::cout << " Size of Outer Vector = " << inVec.size() <<  std::endl;
  std::cout << " Capacity of Outer Vector = " << inVec.capacity() <<  std::endl;
  if(inVec.size() != 0)
  {
    std::cout << " Size of Inner Vector = " << (*(inVec.begin())).size() <<  std::endl;
    std::cout << " Capacity of Inner Vector = " << (*(inVec.begin())).size() <<  std::endl;
  }
  std::cout << "----------------------------------------------------" << std::endl;
}

int main()
{
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << " Initialized mySize to 10 " << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  const unsigned int mySize = 10;

  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << " Initialized a vector of vector with mySize, mySize " << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::vector<std::vector<int> > myVecOfVecs(mySize, mySize);
  printInfo(myVecOfVecs);

  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << " Resized inner vector to size mySize * 2" << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  try
  {
    (*(myVecOfVecs.begin())).resize(mySize * 2);
  }
  catch(...)
  {
    std::cout << "Caught Exception" << std::endl;
  }
  printInfo(myVecOfVecs);

  std::cout << "Cleared vector " << std::endl;
  myVecOfVecs.clear();
  printInfo(myVecOfVecs);

}
