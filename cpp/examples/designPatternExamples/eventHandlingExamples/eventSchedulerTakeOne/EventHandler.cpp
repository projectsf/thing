#include "EventHandler.h"
#include "EventManager.hpp"



EventHandler::EventHandler(string name) 
	: name(name)
{
	EventManager::getInstance()->subscribe(this);
}

EventHandler::~EventHandler()
{
}


string EventHandler::getName() const
{
	return name;
}
