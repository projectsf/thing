#include "EventManager.hpp"

EventManager::EventManager* EventManager::instance = 0;

EventManager::EventManager()
{
}

EventManager* EventManager::getInstance()
{
	if(!instance)
		instance = new EventManager();
	return instance;
}

void EventManager::subscribe(EventHandler* handler)
{
	std::cout << "EventManager::subscribe() - EventHandler: '" << handler->getName() << "' subscribed" << std::endl;
	eventHandlers.insert(handler);
}

void EventManager::publish(const AbstractEvent& event)
{
	if( event.getEventType() == EventTypes::IMMEDIATE_EVENT ) 
	{
		std::cout << "EventManager::publish() - Event scheduled to dispatch immediately" << std::endl;
		dispatch();
	}
	else if ( event.getEventType() == EventTypes::SCHEDULED_EVENT ) 
	{
		const ScheduledEvent& scheduledEvent = const_cast<ScheduledEvent&>(dynamic_cast<const ScheduledEvent&>(event));
		std::cout << "EventManager::publish() - Event scheduled to dispatch with the following terms: " << std::endl;
		std::cout << "\t Frequency = " << scheduledEvent.getFreq() << ", start = " << scheduledEvent.getStart() << " end = " << scheduledEvent.getEnd() << endl;
		eventSchedulers.push_back( new EventScheduler(scheduledEvent) );
	}
}

void EventManager::dispatch()
{
	boost::mutex::scoped_lock lock(mtx);
	set<EventHandler*>::iterator iter = eventHandlers.begin();
	set<EventHandler*>::iterator end = eventHandlers.end();
	for( ; iter != end; ++iter)
	{
		(*iter)->handleEvent();
	}

}
