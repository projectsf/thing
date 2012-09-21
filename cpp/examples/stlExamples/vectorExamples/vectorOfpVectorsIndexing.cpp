/**
 * Test creates a vector<vector<T>>
 * and iterates through it, while investigating
 * different indexing functionality, include operator[]
 * , pointer arithmetic and references
 *
 * @file vectorOfpVectorsIndexing.cpp
 */


#include <iostream>
#include <vector>

using namespace std;

int main()
{
  typedef unsigned int T;

  //constants
  const size_t sizeOuterVec = 2;
  const size_t sizeInnerVec = 4;
  
  //declare vectors
  vector<vector<T> > myVec;
  
  pVec = new vector<T>; 
  
  (*pVec).push_back(1);
  (*pVec).push_back(1);
  myVec.push_back(pVec);
  vector<T>& rVec = (*(*(myVec.begin())));

  pVec = new vector<T>; 
  (*pVec).push_back(2);
  (*pVec).push_back(2);
  myVec.push_back(pVec);

  rVec[0] = 10;
  cout << "rvec[0]" << rVec[0] << endl;
  cout << "myVec[0][0] = " << (*myVec[0])[0] << endl;
  cout << "myVec[0][1] = " << (*myVec[0])[1] << endl;
  cout << "myVec[1][0] = " << (*myVec[1])[0] << endl;
  cout << "myVec[1][1] = " << (*myVec[1])[1] << endl;

  //delete


}
