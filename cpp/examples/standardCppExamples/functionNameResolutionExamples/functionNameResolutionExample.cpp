/** Test code looks at function name resolutions
 *
 * Lessons learned:
 * <ul>
 * <li> Non-template functions take higher precedence
 * over template functions.
 * <li> If no non-template function is found than the
 * most specific template specialization is used
 * <li> If no template specialization is found than
 * the generic function template is used
 * </ul>
 *
 * @file functionNameResolution.cpp
 */


#include <iostream>


//function template of type T
template<typename T>
void printString(T in)
{
  std::cout << "In typename<T> printString(T) " << std::endl;
}

//function template specialized for int
template<>
void printString(int in)
{
  std::cout << "In typename<> printString(int) " << std::endl;
}

//function template of type T
// void printString(int in)
// {
//   std::cout << "In printString(int) " << std::endl;
// }


int main()
{
  int myInt = 3;

  printString(myInt);

}
