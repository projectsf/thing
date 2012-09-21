#ifndef PRODUCER_H
#define PRODUCER_H

#include <pthread.h>
#include <boost/shared_ptr.hpp>
#include "Event.h"
#include <iostream>
#include <appfw/Monitor.hpp>
#include <appfw/Thread.hpp>
#include <appfw/Runnable.hpp>
#include "TestChannel.h"

using namespace std;
using namespace boost;
using namespace appfw;



class Producer : public Runnable
{
	public:
		Producer(TestChannel<shared_ptr<Event> >* channel, unsigned int numberIterations);
		~Producer();
		void start();
		void run();
	private:
		TestChannel<shared_ptr<Event> >* channel;
		const unsigned int numberIterations;
		Thread thread;
		Monitor monitor;

};

#endif


