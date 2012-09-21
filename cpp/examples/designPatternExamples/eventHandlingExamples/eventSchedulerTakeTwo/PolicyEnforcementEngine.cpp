#include "PolicyEnforcementEngine.hpp"
#include "DateAndTime.hpp"

PolicyEnforcementEngine::PolicyEnforcementEngine* PolicyEnforcementEngine::instance = 0;

PolicyEnforcementEngine::PolicyEnforcementEngine()
	: thread(this)
{
	thread.create();
}

PolicyEnforcementEngine* PolicyEnforcementEngine::getInstance()
{
	if(!instance)
		instance = new PolicyEnforcementEngine();
	return instance;
}

PolicyEnforcement* PolicyEnforcementEngine::popContainer()
{
	boost::mutex::scoped_lock lock(mtx);
	PolicyEnforcement* policyEnforcement;
	PolicyEnforcementContainerIterator iter = policyEnforcements.begin();
	policyEnforcement = (*iter);
	policyEnforcements.erase(iter);
	return policyEnforcement;
}

void PolicyEnforcementEngine::run()
{
	PolicyEnforcement* aPolicyEnforcement;
	PolicyEnforcementContainerIterator iter;
	DateAndTime currentTime;
	int waitingSleepTime = 1;
	int sleepTimeSeconds = 1;
	
	while (1)
	{
		if(policyEnforcements.size() != 0) 
		{
			currentTime.update();
			{
				boost::mutex::scoped_lock lock(mtx);
				iter = policyEnforcements.begin();
			}
			std::cout << "PolicyEnforcementEngine::run() - First element: '" << (*iter)->getName() << "' has start time = " << (*iter)->getStart() << endl;
			std::cout << "PolicyEnforcementEngine::run() - Current time: '" << currentTime << endl;
			
			if (currentTime == (*iter)->getStart() )
			{
				std::cout << "PolicyEnforcementEngine::run() - Removing and running top element in PolicyEnforcement Container ..." << endl;
				aPolicyEnforcement = popContainer();
				aPolicyEnforcement->run();
			}
			else
			{
				std::cout << "PolicyEnforcementEngine::run() - Waiting to run next PolicyEnforcement ..." << endl;
				sleep(waitingSleepTime);
			}
			
		}
		else
		{
			std::cout << "PolicyEnforcementEngine::run() - Waiting for new PolicyEnforcements ..." << endl;
			sleep(waitingSleepTime);
		}
	}
}
		
void PolicyEnforcementEngine::add(PolicyEnforcement* policyEnforcement)
{
	boost::mutex::scoped_lock lock(mtx);
	DateAndTime currentTime;
	std::cout << "PolicyEnforcementEngine::add() - A PolicyEnforcement '" << policyEnforcement->getName() << "' was added with the following parameters: " << std::endl;
	std::cout << "\t" << "Start = " << policyEnforcement->getStart() << ", End = " << policyEnforcement->getEnd() << " and Freq = " << policyEnforcement->getFreq() << std::endl;
	std::cout << "\t" << "CurrentTime is: " << currentTime << endl;
	policyEnforcements.insert(policyEnforcement);
}

void PolicyEnforcementEngine::remove(PolicyEnforcement* policyEnforcement)
{
	std::cout << "PolicyEnforcementEngine::remove() - Not supported at this point " << std::endl;
}





