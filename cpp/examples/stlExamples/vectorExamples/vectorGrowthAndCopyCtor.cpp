/** Example code looks at: Vector growth due to push_back and when copy ctor is called for
 * call-by-value and call-by-reference
 *
 * Lessons learned:
 * <ul>
 * <li> Vectors grow by a factor of 2 as the memory is needed
 * <li> At initialization vector.capacity() = 0
 * <li> Vector should be initiatialized to known size at contruction
 * <li> Second best strategy would be to use resize() or reserve()
 * for efficiency, esp if vector size is known at compile time
 * </ul>
 *
 * @file vectorGrowthAndCopyCtor.cpp
 */

#include <iostream>
#include <vector>

using namespace std;
using std::vector;


// *****************************************************/
// Class constructed to help understand most efficient
// way to pass and modify vector<T>.
// First doIncrement() returns a reference to a vector
// The second doIncrement() modifies the second vector
// in the parameter list
// *****************************************************/

template<class T>
class Increment
{
public:
  Increment()
  {
    temp.resize(1);
  }

  //This method calls the copy constructor once 
  //on the return
  vector<T>& doIncrement(const vector<T>& in)
  {
    temp[0] = in[0] + 1;
    return temp;
  }

  //The vector<> copy constructor is not called in this 
  //method
  void doIncrement(const vector<T>& in, vector<T>& out)
  {
    out[0] = in[0] + 1;
  }

private:
  vector<T> temp;
};

int main()
{

  vector<int> topInVec;
  const size_t vecSize = 10;
  
  //**************************************************/
  //this section is looking at how a vector grows
  //**************************************************/

  ///how big is topInVec when it's constructed
  cout << "topInVec is this big at construction: " << topInVec.capacity() << endl;

  //push an element on topInVec
  topInVec.push_back(1);

  //how big is topInVec after the push_back()
  cout << "topInVec is this big after push_back(): " << topInVec.capacity() << endl;

  //push vecSize more and cout capacity
  for(unsigned int ii=0;ii<vecSize;++ii)
  {
    topInVec.push_back(ii);
    cout << "topInVec is this big after push_back(): " << topInVec.capacity() << endl;
  }


  //*************************************************
  //this section is invoking the different doIncrement methods
  //to monitor copying
  //*************************************************

#ifdef MONITOR_COPYCTOR

  Increment<int> increment;

  //using first method to return a modified vector
  vector<int> topOutVec = increment.doIncrement(topInVec);

  //print out returned vector
  cout << "Return vector after first doIncrement() call" << endl;
  for(vector<int>::iterator iter = topOutVec.begin();
      iter!= topOutVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }

  //using second method to return a modified vector
  increment.doIncrement(topOutVec, topInVec);

  //print out returned vector
  cout << "Return vector after first doIncrement() call" << endl;
  for(vector<int>::iterator iter = topInVec.begin();
      iter!= topInVec.end();
      ++iter)
  {
    cout << *iter << endl;
  }

#endif

  
}
