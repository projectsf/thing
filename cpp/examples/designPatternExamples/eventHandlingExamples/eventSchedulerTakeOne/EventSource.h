#ifndef EVENTSOURCE_H
#define EVENTSOURCE_H

#include <string>
#include <vector>
#include "AbstractEvent.hpp"
#include "ScheduledEvent.hpp"

using namespace std;

class EventSource
{
	public:
		EventSource(string);
		~EventSource();
		void run();
		string getName() const;
	protected:
		string name;
		vector<AbstractEvent* > events;

};
#endif
