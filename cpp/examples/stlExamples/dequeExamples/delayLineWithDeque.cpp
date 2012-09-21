/** Example looks at using a deque to implement a delay line
 *
 * @file delayLineWithDeque.cpp
 */

#include <iostream>
#include <deque>

using namespace std;

int main()
{
  const size_t length = 16;
  const unsigned int numIterations = 16;
  typedef unsigned int T;

  //init deque to be of size=length
  deque<T> myDeque(length);

  //populate vector with incrementing sequence
  //and print out at every new entry

  for(unsigned int ii=0;ii<numIterations;++ii)
  {
    myDeque.push_front(ii);
    myDeque.pop_back();
   
    unsigned int index = 0;
    //cout << "Deque contents at " << ii  << "th modify" << endl;
    //print out deque
    for(deque<T>::iterator iter = myDeque.begin();
        iter!= myDeque.end();
        ++iter, ++index)
    {
      //cout << "deque at index = " << index << " ; = " << *iter << endl;
    }
  }



  //testing bit manipulations

  bool a=0,b=1,c=2;

  cout << "a= " << a << " b= " << b << " c= " << c << endl;
  cout << "a ^ a = " << (a^a) << endl;
  cout << "a ^ b = " << (a^b) << endl;
  cout << "b ^ b = " << (b^b) << endl;
  cout << "a ^ c = " << (a^c) << endl;
}
  
  


  

  

