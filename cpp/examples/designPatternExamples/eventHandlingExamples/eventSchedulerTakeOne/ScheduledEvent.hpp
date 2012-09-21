#ifndef SCHEDULEDEVENT_HPP_
#define SCHEDULEDEVENT_HPP_

#include "AbstractEvent.hpp"
#include "DateAndTime.hpp"


class ScheduledEvent : public AbstractEvent
{
	public:
		ScheduledEvent(const string&, const string&, EventType, int, const DateAndTime&, const DateAndTime&);
		virtual ~ScheduledEvent();
		int getFreq() const;
		void setFreq(int);
		void setStart(const DateAndTime&);
		void setEnd(const DateAndTime&);
		const DateAndTime& getStart() const;
		const DateAndTime& getEnd() const;
		EventType getEventType() const;
		
	protected:
		int freq; 
		DateAndTime start; 
		DateAndTime end;

};

#endif /*SCHEDULEDEVENT_HPP_*/
