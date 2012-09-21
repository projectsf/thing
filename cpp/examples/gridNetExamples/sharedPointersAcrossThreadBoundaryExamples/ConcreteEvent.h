#ifndef CONCRETEEVENT_H
#define CONCRETEEVENT_H
 
#include "Event.h"
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;


class ConcreteEvent : public Event
{
	public:
		ConcreteEvent(const string& name);
		virtual ~ConcreteEvent();
		virtual const string& getName() const;
		virtual shared_ptr<Event> clone() const;
	private:
		string name;
};
#endif
