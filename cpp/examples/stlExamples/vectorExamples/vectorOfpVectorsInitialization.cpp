/**
 * Test creates a vector<vector<T>* >
 * and iterates through it
 *
 * The code populates a vector<vector<T>* >
 * by calling new for each inner vector
 * and then sizing that inner vector
 * through push_back(). <br>
 *
 * The code populates the vector, writes
 * out the data and then destroys
 * the inner vectors.
 *
 * Questions that triggered this example:
 * <ul>
 * <li> How to create a vector of pointers to vector
 * <li> How to populate and reference
 * inner vectors in when they're
 * referenced through pointers
 * <li> How to destroy inner vectors when they're referenced
 * via pointers
 * </ul>
 * 
 * @file vectorOfpVectorsInitialization.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  typedef unsigned int T;

  //constants
  const size_t sizeOuterVec = 2;
  const size_t sizeInnerVec = 20;
  
  //declare vectors
  vector<vector<T>* > myVec;
  vector<T> tempVec;
  vector<T>* pVec;

  //declare inner and outer iterators
  vector<vector<T>* >::iterator outerIter = myVec.begin();
  vector<T>::iterator innerIter;

  //populate list
  for(unsigned int ii=0;ii<sizeOuterVec;++ii, ++outerIter)
  {
    pVec = new vector<T>;

    //create innerVec 
    for(unsigned int jj=0;jj<sizeInnerVec;++jj)
    {
      (*pVec).push_back(jj+ii);
    }

    myVec.push_back(pVec);

  }

  //write out values
  for(vector<vector<T>* >::iterator tempOuterIter = myVec.begin();
      tempOuterIter!=myVec.end();
      ++tempOuterIter)
  {
    for(vector<T>::iterator tempInnerIter = (**tempOuterIter).begin();
        tempInnerIter!=(**tempOuterIter).end();
        ++tempInnerIter)
    {
      cout << *tempInnerIter << endl;
    }
  }
      
  //delete allocated vector list
  for(vector<vector<T>* >::iterator iter = myVec.begin();
      iter!=myVec.end();
      ++iter)
  {
    delete *iter;
  }
      

}
