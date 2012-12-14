#include <stdlib.h>
#include <stdio.h>


//expected usage ./run.x 4 6 +

int main(int argc, char* argv[])
{
	int operandOne;
	int operandTwo;
	int result = 0;
	char operation[1];
	if (argc != 4)
	{
		printf("usage: run.x [value] [value] [operation]\n");
		exit(-1);
	}
	else
	{
		operandOne = atoi(argv[1]);
		operandTwo= atoi(argv[2]);
		if (*(argv[3]) == '+')
		{
			result = operandOne + operandTwo;
		}
		else
		{
			printf("%s: unsupported operation\n", argv[3]);
			exit(-1);
		}
	}

	printf("requested operation: %d %s %d\n", operandOne, argv[3], operandTwo);
	printf("result: %d\n" , result);
}
