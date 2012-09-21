/**
 * Code proves out that you can copy from a vector to a deque
 * using std::copy()
 *
 * @file vectorToDequeCopy.cpp
 */
 
#include <iostream>
#include <vector>
#include <deque>


int main()
{
  const unsigned int vecSize = 10;
  std::vector<int> vec1(vecSize, 4);
  std::deque<int> vec2(vecSize);

  std::deque<int>::iterator end = vec2.end();

  std::copy(vec1.begin(), vec1.end(), vec2.begin());

  for(std::deque<int>::iterator iter=vec2.begin();
      iter!=end;
      ++iter)
  {
    std::cout << *iter << '\n';
  }
}
