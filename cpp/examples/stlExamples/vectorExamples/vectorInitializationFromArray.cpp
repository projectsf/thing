/**
 * Test code illustrates how to
 * initialize a vector
 *
 * This code illustrated that its possible
 * to initialize a vector<T> with a
 * T[] array style const.
 *
 * @file vectorInitializationFromArray.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Constants
{
  const unsigned int NUM_ELEMENTS = 4;
  const int INT_ARRAY[NUM_ELEMENTS] = {1, 2, 3, 4};
}

int main()
{
  vector<int> myVec(Constants::INT_ARRAY, Constants::INT_ARRAY + Constants::NUM_ELEMENTS );

  for(vector<int>::iterator iter = myVec.begin();
      iter!= myVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }

  
}
