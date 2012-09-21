#include "EventHandler.h"
#include "EventSource.h"
#include "ConcreteEventHandler.h"


int main()
{
	ConcreteEventHandler concreteEventHandler("ID: 9001");
	EventSource eventSource("ID: 1001");
	eventSource.run();
	sleep(360);
}
