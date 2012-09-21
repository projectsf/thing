#include "ConcreteEvent.h"



ConcreteEvent::ConcreteEvent(const string& name) : name(name) 
{
}

ConcreteEvent::~ConcreteEvent()
{
	cout << "Destroying " << this->getName()  << endl;
}


const string& ConcreteEvent::getName() const
{
	return name;
}

shared_ptr<Event> ConcreteEvent::clone() const 
{
	cout << "Cloning " << this->getName() << endl;
	return shared_ptr<Event>(new ConcreteEvent(this->getName()));
}

