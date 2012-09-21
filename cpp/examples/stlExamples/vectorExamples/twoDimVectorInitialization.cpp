/**
 * Test creates a vector<vector<T> >
 * and iterates through it, while investigating
 * different indexing functionality, include operator[]
 * , pointer arithmetic and references
 *
 * Lessons Learned:
 * <ul>
 * <li> 2-d vectors can be size initialized
 * via a 2 argument constructor.  First element
 * sizes outer vector, second element sizes
 * inner vector.  This works because of the
 * vector(size_type __n, const value_type& __value)
 * constructor.  The value_type is constructed
 * using the _value argument.  value_type(__value) is
 * constructed __n times.  Our value_type
 * is std::vector<T>, so __value of those is copied
 * __n times.  Phew..
 * <li> A more explicit way of doing it:
 *   o std::vector<T> tempVec(innerSize);
 *   o std::vector<std::vector<T> > myVec(outerSize, tempVec);
 * <li> indexing into inner vector can be done
 * by way of a (myVec[outerIndex])[innerIndex].
 * <li> outer and inner iterator loops can be
 * used to access/modify 2-d vectors
 * <li> inner vectors can be populated via
 * iterators by indexing off of the desired
 * outer vector, i.e. myVec[2].begin() and
 * myVec[2].end() point to the beginning and
 * end of the 2nd outer vector.
 * </ul>
 *
 * @file twoDimVectorInitialization.cpp
 */


#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printContentsUsingIterators(const std::vector<vector<T> >& inVec)
{
  unsigned int ii = 0;
  unsigned int jj = 0;

  for(typename std::vector<vector<T> >::const_iterator outerVecIter = inVec.begin();
      outerVecIter != inVec.end();
      ++outerVecIter, ++ii)
  {
    jj = 0;
    for(typename std::vector<T>::const_iterator innerVecIter = (*outerVecIter).begin();
        innerVecIter != (*outerVecIter).end();
        ++innerVecIter, ++jj)
    {
      std::cout << " Element[" << ii << "][" << jj << "] = " << *innerVecIter << std::endl;
    }
  }
}

template<typename T>
void printContentsUsingIndices(const std::vector<vector<T> >& inVec)
{
  unsigned int outerSize = inVec.size();
  unsigned int innerSize = inVec[0].size();

  for(unsigned int ii=0; ii<outerSize; ++ii)
  {
    for(unsigned int jj=0; jj<innerSize; ++jj)
    {
      std::cout << " Element[" << ii << "][" << jj << "] = " << (inVec[ii])[jj] << std::endl;
    }
  }
}
  

int main()
{
  typedef unsigned int T;

  //constants
  const size_t sizeOuterVec = 2;
  const size_t sizeInnerVec = 4;
  
  //declare vector using (size_type __n, value_type& __value) ctor
  vector<vector<T> > myVec(sizeOuterVec,sizeInnerVec);

  
  //print out initial contents
  std::cout << " -------------------------------- " << std::endl;
  std::cout << " Initial Contents                 " << std::endl;
  std::cout << " -------------------------------- " << std::endl;
  printContentsUsingIterators(myVec);

  //populate with index
  unsigned int ii = 0;
  std::cout << " -------------------------------- " << std::endl;
  std::cout << " Populating 2-d vector                " << std::endl;
  std::cout << " -------------------------------- " << std::endl;
  for(std::vector<vector<T> >::iterator outerVecIter = myVec.begin();
      outerVecIter != myVec.end();
      ++outerVecIter)
  {

    for(std::vector<T>::iterator innerVecIter = (*outerVecIter).begin();
        innerVecIter != (*outerVecIter).end();
        ++innerVecIter, ++ii)
      {
        *innerVecIter = ii;
      }
  }

  //print out contents with iterators
  std::cout << " -------------------------------- " << std::endl;
  std::cout << " Final  Contents w/iterators      " << std::endl;
  std::cout << " -------------------------------- " << std::endl;
  printContentsUsingIterators(myVec);

  //print out contents with indexing
  std::cout << " -------------------------------- " << std::endl;
  std::cout << " Final  Contents w/indices        " << std::endl;
  std::cout << " -------------------------------- " << std::endl;
  printContentsUsingIndices(myVec);


}
