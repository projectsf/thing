#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Runnable;

class Thread
{
	public:
		Thread(Runnable*);
		void create();
		void dispatch();
		void stop();
		
	protected:
		friend void* threadDispatcher(void *opaque);
		
	private:
		Runnable* runnable;
		pthread_t pThread;
};
#endif
