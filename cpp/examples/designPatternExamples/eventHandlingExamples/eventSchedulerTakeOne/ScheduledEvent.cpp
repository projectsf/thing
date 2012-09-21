#include "ScheduledEvent.hpp"



ScheduledEvent::ScheduledEvent(const string& name, const string& source, EventType eventType, int freq, const DateAndTime& start, const DateAndTime& end) : AbstractEvent(name, source, eventType), freq(freq), start(start), end(end)
{
}


ScheduledEvent::~ScheduledEvent()
{
}


void ScheduledEvent::setFreq(int f)
{
	freq = f;
}

void ScheduledEvent::setStart(const DateAndTime& dt)
{
	start = dt;
}
	
void ScheduledEvent::setEnd(const DateAndTime& dt)
{
	end = dt;
}


int ScheduledEvent::getFreq() const
{
	return freq;
}

const DateAndTime& ScheduledEvent::getStart() const
{
	return start;
}

const DateAndTime& ScheduledEvent::getEnd() const
{
	return end;
}
