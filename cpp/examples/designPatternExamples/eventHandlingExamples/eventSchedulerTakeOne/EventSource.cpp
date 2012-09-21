#include "EventSource.h"
#include "EventManager.hpp"
#include "DateAndTime.hpp"
#include "EventTypes.h"


EventSource::EventSource(string name)
	: name(name)
{
		//Function params
	DateAndTime start;
	DateAndTime end;
	int startOffset;
	int endOffset;
	int freq;
	
	//ImmediateEventOne params
	events.push_back( new AbstractEvent("ImmediateEventOne", name, EventTypes::IMMEDIATE_EVENT) );

	//ScheduledEventOne params
	startOffset = 10;
	start.operator+(startOffset);
	endOffset = 30;
	end.operator+(endOffset);
	freq = 2;
	events.push_back( new ScheduledEvent("ScheduledEventOne", name, EventTypes::SCHEDULED_EVENT, freq, start, end) );
	
	//ScheduledEventTwo params
	start.updateTimeOfDay();
	end.updateTimeOfDay();
	startOffset = 20;
	start.operator+(startOffset);
	endOffset = 30;
	end.operator+(endOffset);
	freq = 1;
	events.push_back( new ScheduledEvent("ScheduledEventTwo", name, EventTypes::SCHEDULED_EVENT, freq, start, end) );
		
}

EventSource::~EventSource()
{
	vector<AbstractEvent*>::iterator iter = events.begin();
	vector<AbstractEvent*>::iterator end = events.end();
	
	for( ; iter!=end; ++iter)
	{
		delete *iter;
	}
}

void EventSource::run()
{
	vector<AbstractEvent*>::iterator iter = events.begin();
	vector<AbstractEvent*>::iterator end = events.end();
	
	for( ; iter!=end; ++iter)
	{
		EventManager::getInstance()->publish(*(*iter));
	}

}

string EventSource::getName() const
{
	return name;
}


