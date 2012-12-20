#include <stdio.h>


void printValues(int* values, int length)
{
	for (unsigned int ii = 0; ii < length; ++ii) 
	{
		printf("Value: %d\n", values[ii]);
	}
		
}

int main(int argc, char* argv[])
{
	//char value = 0x0 | 0x03;
	int values[3] =  {0,1,2};
	//printf("Value: %d\n", (int)value);
	printValues(values, 3);
}
