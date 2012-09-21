#ifndef EVENT_H
#define EVENT_H
 
#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;


class Event
{
	public: 
		virtual ~Event();
		virtual const string& getName() const = 0;
		virtual shared_ptr<Event> clone() const = 0;
};

#endif
