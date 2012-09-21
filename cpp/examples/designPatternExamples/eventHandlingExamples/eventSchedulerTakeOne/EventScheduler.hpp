#ifndef EVENTSCHEDULER_HPP
#define EVENTSCHEDULER_HPP

#include "Thread.hpp"
#include "Runnable.hpp"
#include "ScheduledEvent.hpp"
#include <iostream>


using namespace std;


class EventScheduler : public Runnable 
{
	public:
		EventScheduler(const ScheduledEvent& scheduledEvent);
		
		virtual void run();
		
	private:
		ScheduledEvent scheduledEvent;
		Thread thread;
};

#endif
