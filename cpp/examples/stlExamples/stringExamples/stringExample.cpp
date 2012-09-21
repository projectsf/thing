/**
 * Example looks at strings and how to convert ints to strings
 *
 * Lessons Learned
 * <ul>
 * <li> Can't convert an int to a string via a string constructor
 * <li> Can't figure out how to use c style itoa or atoi calls
 * </ul>
 *
 * @file stringExample.cpp
 */


#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


int main()
{
  int myInt = 3;
  std::string myString("my int is: ");

  std::string longString = myString + std::string(itoa(myInt));

  std::cout << longString << std::endl;
  
}
