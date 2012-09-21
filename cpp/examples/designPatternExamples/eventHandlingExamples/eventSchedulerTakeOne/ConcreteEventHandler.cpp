#include "ConcreteEventHandler.h"
#include "DateAndTime.hpp"

ConcreteEventHandler::ConcreteEventHandler(string name) 
	:	EventHandler(name)
{
}

ConcreteEventHandler::~ConcreteEventHandler()
{
}

void ConcreteEventHandler::handleEvent()
{
	cout << "ConcretEventHandler::handleEvent() -- '" << name << "' is handling event at: ";
	DateAndTime dateAndTime;
	cout << dateAndTime.getDateAndTime() << endl;
}



