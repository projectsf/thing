/**
 * Example looks at using p threads
 *
 * @file pThreadsExample.cpp
 */
 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define NUM_THREADS	5

using namespace std;

class Foo
{
	public:
		Foo(){}
		~Foo(){cout << "destroying foo" << endl;}
		
};

void *PrintHello(void *threadid)
{
	Foo foo;
	pthread_mutex_t lock;
	pthread_mutexattr_t mattr;
	pthread_mutexattr_init(&mattr);
	pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&lock, &mattr);
	pthread_mutex_lock(&lock);
	printf("Hello World!\n");
	sleep(5);
	printf("Goodbye World!\n");
	pthread_exit(NULL);
	pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int rc, t;
	for(t=0;t<NUM_THREADS;t++)
	{
 		printf("Creating thread %d\n", t);
		rc = pthread_create(&thread, NULL, PrintHello, (void *)t);

  		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
    	}
  	}
	
	pthread_exit(NULL);
	sleep(2);
}
