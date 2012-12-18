#include <stdio.h>
#include <string.h>


void reverseStringWithTempString(char* str)
{
	int length = strlen(str);
	char temp[length+1]; 

	//copy string backwards to temp
	for (int ii = (length - 1); ii >= 0 ; --ii)
	{
		temp[length-ii-1] = str[ii];
	}

	strncpy(str, temp, length);
}

void reverseStringInPlace(char* str)
{
	int length = strlen(str);

	//copy string backwards to temp
	for (int ii = 0; ii < length/2 ; ++ii)
	{
		char swap = str[ii];
		str[ii] = str[length-ii-1];
		str[length-ii-1] = swap;
	}
}

int main()
{
	char string[] = "reverseme";
	printf("Original string: %s\n", string);

	reverseStringInPlace(string);

	printf("Reversed string: %s\n", string);

}
