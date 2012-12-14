#include <stdio.h>
#include <string.h>


void reverseString(char* str)
{
	int length = strlen(str);
	char temp[length+1]; 

	//copy string backwards to temp
	for (int ii = (length - 1); ii >= 0 ; --ii)
	{
		printf("i1: %d, i2: %d\n", (length-ii-1), ii);
		temp[length-ii-1] = str[ii];
	}

	strncpy(str, temp, length);
}

int main()
{
	char string[] = "reverseme";

	reverseString(string);

	printf("%s\n", string);
}
