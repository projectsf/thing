#ifndef ABSTRACTEVENT_HPP_
#define ABSTRACTEVENT_HPP_

#include "EventTypes.h"
#include <string>

using namespace std;
using EventTypes::EventType;


class AbstractEvent
{
	public:
		AbstractEvent(const string&, const string&, EventType);
		virtual ~AbstractEvent();
		const string& getName() const;
		const string& getSource() const;
		EventType getEventType() const;
		
	protected:
		string source;
		string name;
		EventType eventType;

};

#endif /*ABSTRACTEVENT_HPP_*/
