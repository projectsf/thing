#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <iostream>

using namespace std;

class EventHandler
{
	public:

		virtual void handleEvent() = 0;
		class HandleObject : public unary_function<EventHandler*, void> {
			public:
				HandleObject(){};
				void operator()(EventHandler* eventHandler)
				{
					eventHandler->handleEvent();
				}
		};
		
		string getName() const;
		~EventHandler();
		
	protected:
		EventHandler(string name);
		string name;
};

#endif
