/**
 * Example looks at using p threads with STL vectors
 *
 * @file vecOfpThreadsExample.cpp
 */
 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define NUM_THREADS	380

using namespace std;

void *PrintHello(void *threadid)
{
	//printf("\n%d: Hello World!\n", threadid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	vector<pthread_t*> threads;
	pthread_attr_t attr;
	size_t size;
	size_t additionalStackSize = 2048;
	size = additionalStackSize;
	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, size); 
	int rc, t;
	for(t=0; t < NUM_THREADS; t++)
	{
 		//printf("Creating thread %d\n", t);
  	threads.push_back(new pthread_t);
  	rc = pthread_create(threads[t], &attr, PrintHello, (void *)t);
		if (rc)
		{
			printf("ERROR: pthreadd_create() : is %s\n", strerror(errno));
			exit(-1);
    }
  }
  printf("All threads created \n");
	sleep(100);
}
