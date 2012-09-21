#include "AbstractEvent.hpp"


AbstractEvent::AbstractEvent(const string& name, const string& source, EventType eventType) : 
		source(source), name(name), eventType(eventType)
{
}


AbstractEvent::~AbstractEvent()
{
}

EventType AbstractEvent::getEventType() const
{
	return eventType;
}


const string& AbstractEvent::getName() const
{
	return name;
}

const string& AbstractEvent::getSource() const
{
	return source;
}
