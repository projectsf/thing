#include "EventScheduler.hpp"
#include "EventManager.hpp"
#include "ScheduledEvent.hpp"
#include "DateAndTime.hpp"


EventScheduler::EventScheduler(const ScheduledEvent& scheduledEvent)
	: scheduledEvent(scheduledEvent), thread(this)
{
	thread.create();
}


void EventScheduler::run()
{
	DateAndTime currentTime;
	
	while(currentTime < scheduledEvent.getStart())
	{
		sleep(1);
		currentTime.updateTimeOfDay();
	}
	
	
	while( ( currentTime >= scheduledEvent.getStart() ) && ( currentTime <= scheduledEvent.getEnd() ) )
	{
		EventManager::getInstance()->dispatch();
		sleep(scheduledEvent.getFreq());
		currentTime.updateTimeOfDay();
		cout << "EventScheduler::run() -- CurrentTime = " << currentTime << endl;
	}
		
	thread.stop();
}
