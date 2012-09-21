#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <set>
#include <vector>
#include "EventHandler.h"
#include "AbstractEvent.hpp"
#include "EventScheduler.hpp"
#include "ScheduledEvent.hpp"
#include <boost/thread/mutex.hpp>

using namespace std;


class EventManager
{
	public:

		static EventManager* getInstance();
		void subscribe(EventHandler* handler);
		void publish(const AbstractEvent&);
		void dispatch();

	private:
		static EventManager* instance;
		boost::mutex mtx;
		vector<EventScheduler*> eventSchedulers;
		EventManager();
		set<EventHandler*> eventHandlers;
};
#endif

