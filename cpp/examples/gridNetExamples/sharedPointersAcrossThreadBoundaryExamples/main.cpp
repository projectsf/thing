
#include "Producer.h"
#include "Consumer.h"
#include "TestChannel.h"
#include <pthread.h>
#include <appfw/Thread.hpp>
#include "Event.h"
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;



int main(int argc, char *argv[])
{
	const unsigned int numberIterations = 5;
	const unsigned int sleepTime = numberIterations + 2;
	Thread::initialize();
	TestChannel<shared_ptr<Event> > channel;
	Producer producer(&channel, numberIterations);
	Consumer consumer(&channel, numberIterations);
	producer.start(); 
	consumer.start(); 
	
	sleep(sleepTime);
	
	return 0;
}
