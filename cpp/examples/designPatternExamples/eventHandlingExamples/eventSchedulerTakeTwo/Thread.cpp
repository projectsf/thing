#include "Thread.hpp"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* threadDispatcher(void *opaque)
{
	Thread* thread = reinterpret_cast<Thread*>(opaque);
	thread->dispatch();
	
	return 0;
}


Thread::Thread(Runnable* runnable)
	: runnable(runnable)
{}

void Thread::create()
{
	int rc = pthread_create(&pThread, NULL, ::threadDispatcher, this);
	if (rc != 0)
	{
		std::cout << "Thead::create() --  Can't start thread" << std::endl;
	}
}

void Thread::dispatch()
{
	runnable->run();
}

void Thread::stop()
{
	pthread_exit(NULL);
}
