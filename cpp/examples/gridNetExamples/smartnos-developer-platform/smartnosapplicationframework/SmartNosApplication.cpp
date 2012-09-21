#include "./include/SmartNosApplication.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "./include/SmartNosClient.hpp"
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

SmartNosApplication::SmartNosApplication(const string& applicationIdentifier) :
applicationIdentifier(applicationIdentifier), isRunning(false), stopRunning(false)
{
	subscribe();
}

SmartNosApplication::~SmartNosApplication()
{
	unsubscribe();
}

const string& SmartNosApplication::getApplicationIdentifier() const
{
	return applicationIdentifier;
}

void SmartNosApplication::subscribe()
{
	cout << applicationIdentifier << " is registering with SmartNos" << endl;
	SmartNosClient::getInstance()->subscribe(this);
}

void SmartNosApplication::unsubscribe()
{
	cout << applicationIdentifier << " is unregistering with SmartNos" << endl;
	SmartNosClient::getInstance()->unsubscribe(this);
}

void SmartNosApplication::run()
{
	while (!stopRunning)
	{
		vector<shared_ptr<ApplicationMessage> > applicationMessages;
		SmartNosClient::getInstance()->getMessages(this->getApplicationIdentifier(), applicationMessages);
		for (vector<shared_ptr<ApplicationMessage> >::const_iterator iter = applicationMessages.begin(); iter != applicationMessages.end(); ++iter)
		{
			handleApplicationMessage(*iter);
		}
	}
}

void SmartNosApplication::start()
{
	cout << "Starting application : " << applicationIdentifier << endl;
	isRunning = true;
}

void SmartNosApplication::stop()
{
	cout << "Stopping application : " << applicationIdentifier << endl;
	isRunning = false;
}

void SmartNosApplication::handleApplicationMessage(shared_ptr<ApplicationMessage> applicationMessage)
{
	if (ApplicationMessage::ApplicationLifecycle == applicationMessage->getMessageType())
	{
		shared_ptr<ApplicationLifecycleMessage> applicationLifecycleMessage = shared_dynamic_cast<ApplicationLifecycleMessage>(applicationMessage);
		if (ApplicationLifecycleMessage::Start == applicationLifecycleMessage->getAction())
		{
			this->start();
		}
		else if (ApplicationLifecycleMessage::Stop == applicationLifecycleMessage->getAction())
		{
			if (isRunning = true)
			{
				this->stop();
			}
		}
		else
		{
			cout << "Unsupported application lifecycle message for application: " << applicationIdentifier << endl;
			cout << "Message: " << applicationLifecycleMessage->getMessage() << endl;
		}
	}

	else if (ApplicationMessage::ApplicationMessagePayload == applicationMessage->getMessageType())
	{
		if (isRunning)
		{
			cout << "Forwarding message to application: " << applicationIdentifier << endl;
			shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage = shared_dynamic_cast<ApplicationPayloadMessage>(applicationMessage);
			this->handleApplicationPayloadMessage(applicationPayloadMessage);
		}
		else 
		{
			cout << "Application payload messages not supported until application starts" << endl;
		}
	}

}
