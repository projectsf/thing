#ifndef TESTCHANNEL_H
#define TESTCHANNEL_H

#include <pthread.h>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <deque>
#include <appfw/Monitor.hpp>
#include <appfw/ScopedLock.hpp>

using namespace std;
using namespace boost;
using namespace appfw;

template<typename T>
class TestChannel
{
	public:
		TestChannel()  : container(0) 
		{
		}
		
		~TestChannel()
		{
		}
				
		void put(const T element)
		{
			appfw::ScopedLock lock(monitor);
			container.push_back(element);
			monitor.notify();
		}
		
		T take()
		{
			ScopedLock lock(monitor);
			while (container.size() == 0)
			{
				monitor.wait();
			}
		
			T item = container.front();
			container.pop_front();
			return item;
		}
	private:
		appfw::Monitor monitor;
		deque<T> container;
		
};

#endif


