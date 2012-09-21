#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

boost::shared_ptr<int> pInt;

class Shape
{
	public:
		Shape(const std::string& name) : m_name(name)
		{
		}
	 
		~Shape() { std::cout << "Destroying .." << std::endl; }
  
	private:
		std::string m_name;
};

void *PrintHello(void *threadid)
{
	pInt(
	pthread_exit(NULL);
}


int main()
{
	pthread_t threadOne, threadTwo;
	int value = 3;
	int statusOne = pthread_create(&threadOne, NULL, PrintHello, (void *)value);
	int statusTwo = pthread_create(&threadTwo, NULL, PrintHello, (void *)value);
	
	if (statusOne)
	{
		printf("ERROR; return code from pthread_create() for threadOne is %d\n", statusOne);
		exit(-1);
	}
	
	if (statusTwo)
	{
		printf("ERROR; return code from pthread_create() for threadTwo is %d\n", statusTwo);
		exit(-1);
	}
	
	pthread_exit(NULL);
}





