/** Example code looks at implementing a delay line using
 * vectors, using stl algorithms and back_inserter()
 *
 * @file delayLineWithVector.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;


int main()
{
  typedef int T;
  const unsigned int numIterations = 5;
  const size_t sizeInVec   = 4;
  const unsigned int delay = 1;
  const size_t sizeFillVec = delay;
  const size_t sizeOutVec  = sizeInVec;

  //declare vectors 
  vector<T> inVec, fillVec;

  //outVec is already created in sunnyvale systemC framework (ssf)
  vector<T> outVec(sizeOutVec);

  //reserve mem for vectors
  inVec.reserve(sizeInVec);
  fillVec.reserve(sizeFillVec);
  
  //iterate through logic numIterations 
  for(unsigned int jj=0;jj<numIterations;++jj)

  //populate inVec with all 1's
  for(unsigned int ii=0;ii<sizeInVec;++ii)
  {
    inVec.push_back(100+ii);
  }

  //populate fillVec with all zeroes
  for(unsigned int ii=0;ii<sizeFillVec;++ii)
  {
    fillVec.push_back(ii);
  }

  //copy fillVec to outVec
  copy(fillVec.begin(),fillVec.end(),outVec.begin());

  //create iterator that points to (sizeInVec - delay)-th element in inVec
  vector<T>::iterator inVecIter = inVec.begin()+(sizeInVec-delay);

  //create iterator that points to delay-th element in outVec
  vector<T>::iterator outVecIter = outVec.begin()+(delay);

  //copy sizeInVec-delay elements of inVec to outVec
  copy(inVec.begin(),inVecIter,outVecIter);

  //copy final <delay> elements of inVec to fillVec
  copy((inVecIter),inVec.end(),fillVec.begin());

  //print out outVec 
  cout << "outVec = " << endl;
  for(vector<int>::iterator iter = outVec.begin();
      iter!= outVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }

  cout << "fillVec= " << endl;
  for(vector<int>::iterator iter = fillVec.begin();
      iter!= fillVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }

}
