#include <iostream>
void foo(int * pInt)
{
  int temp = 5;
  pInt = &temp;
  std::cout << "Value in foo(): " << *pInt << std::endl;
}

//void foo(const int* pInt)
//{
//  *pInt = 5;
//}



int main()
{
  int myInt = 8;
  int * pInt = new int;
  *pInt = 7;

  foo(&myInt);

  std::cout << "value: " << *pInt << std::endl;


}
