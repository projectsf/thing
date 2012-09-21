#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Runnable.hpp"

using namespace std;


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
