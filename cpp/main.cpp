#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdint.h>

using namespace std;

int main()
{


#ifdef PRINT_ONE
	cout << "1" << endl;
#endif
#ifdef PRINT_TWO
	cout << "2" << endl;
#endif
#if defined PRINT_TWO && defined PRINT_ONE
	cout << "BOTH" << endl;
#endif
	
}
