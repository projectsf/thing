#ifndef CONCRETEEVENTHANDLER_H
#define CONCRETEEVENTHANDLER_H

#include "EventHandler.h"
#include <string>

using namespace std;

class ConcreteEventHandler : public EventHandler
{
	public:
		ConcreteEventHandler(string);
		void handleEvent();
		~ConcreteEventHandler();
		
	private:
};

#endif
