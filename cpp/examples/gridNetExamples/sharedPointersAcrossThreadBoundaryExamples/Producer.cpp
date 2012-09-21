#include "Producer.h"
#include "TestChannel.h"
#include <boost/lexical_cast.hpp>
#include "ConcreteEvent.h"


Producer::Producer(TestChannel<shared_ptr<Event> >* channel, unsigned int numberIterations) : channel(channel), numberIterations(numberIterations), thread("Producer", this)
{
}

Producer::~Producer()
{
}

/* starts thread */
void Producer::start()
{
	cout << "Starting Producer thread" << endl;
	thread.start();
}

void Producer::run()
{
	unsigned int count = 0;
	for (unsigned int ii=0; ii<numberIterations; ++ii)
	{
		cout << "Posting new event 'Event-" << count << "' to Channel" << endl;
		ConcreteEvent event("Event-" + lexical_cast<string>(++count));
		channel->put(event.clone());
		sleep(1);
	}
}


