/**
 * Code investigates how resize and clear affect
 * a vectors size and capacity
 *
 * Lessons learned
 * <ul>
 * <li> An empty vector has size=0 and capacity=0
 * after construction
 * <li> A resize(x) modifies a vector to have
 * size=0 and capacity=0
 * <li> A clear() clears both the size and capacity
 * for a vector
 * </ul>
 *
 * @file vectorResizing.cpp
 */

#include <iostream>
#include <vector>

/**
 * Function prints out size and capacity
 * information for a vector<T>
 */
template<typename T>
void printInfo(std::vector<T> inVec)
{
  std::cerr << "Size of Vector = " << inVec.size() <<  std::endl;
  std::cout << "Capacity of Vector = " << inVec.capacity() <<  std::endl;
}

int main()
{

  std::cout << "Initialized a vector of size 0 " << std::endl;
  std::vector<int> myVec;
  printInfo(myVec);

  std::cout << "Resized vector to size 10" << std::endl;
  const unsigned int mySize = 10;
  myVec.resize(mySize);
  printInfo(myVec);


  std::cout << "Cleared vector " << std::endl;
  myVec.clear();
  printInfo(myVec);

}
