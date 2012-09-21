#include "Consumer.h"
#include "TestChannel.h"
#include <boost/lexical_cast.hpp>
#include "ConcreteEvent.h"


Consumer::Consumer(TestChannel<shared_ptr<Event> >* channel, unsigned int numberIterations) : channel(channel), numberIterations(numberIterations), thread("Consumer", this)
{
}

Consumer::~Consumer()
{
}

/* starts thread */
void Consumer::start()
{
	cout << "Starting Consumer thread" << endl;
	thread.start();
}

void Consumer::run()
{
	/* With lock, helgrind happy, without lock, helgrind angry */
	//ScopedLock lock(monitor);
	for (unsigned int ii=0; ii<numberIterations; ++ii)
	{
		shared_ptr<Event> event = channel->take();
		cout << "Taking event '" << event->getName() << "' from Channel" << endl;
		sleep(1);
	}
}


