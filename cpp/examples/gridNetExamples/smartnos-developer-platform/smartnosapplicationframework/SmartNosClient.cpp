#include "./include/SmartNosClient.hpp"
#include "ClientSubscriptionMessage.hpp"
#include <iostream>
#include "DomainClientSocket.hpp"
#include "DomainSocketException.hpp"

using namespace std;
using namespace boost;

void *watch(void *opaque)
{
	SmartNosClient* smartNosClient;
	smartNosClient = reinterpret_cast<SmartNosClient*>(opaque);
	
	//create application message server socket
	DomainServerSocket  applicationMessageServerSocket(4445);
	int applicationMessageServerSocketFd = applicationMessageServerSocket.getSocketFd();

	fd_set read_fds;
	fd_set active_fds;
	FD_ZERO(&active_fds);
	FD_SET(applicationMessageServerSocketFd, &active_fds);
	unsigned int fdMax = applicationMessageServerSocketFd + 1; 

	while (true)
	{
		read_fds = active_fds;
		int status = select(fdMax, &read_fds, NULL, NULL, NULL);
		if ( -1 == status) 
		{
			cout << "select error" << endl;
		}
		else
		{
			for (unsigned int ii = 0 ; ii < fdMax; ++ii)
			{
		 		if (FD_ISSET(ii, &read_fds))
				{
					if (applicationMessageServerSocketFd == ii)
					{
						string message;
						try 
						{
							DomainServerSocket new_sock;
							applicationMessageServerSocket.accept ( new_sock );

							new_sock >> message;


						}
						catch (DomainSocketException& exc)
						{
							cout << "Caught exception: " << exc.description() << endl;
						}

						//inspect type (factory later)
						ApplicationMessage applicationMessage(message);
						if (applicationMessage.getMessageType() == ApplicationMessage::ApplicationLifecycle)
						{
							shared_ptr<ApplicationLifecycleMessage> applicationLifecycleMessage(new ApplicationLifecycleMessage(message));
							smartNosClient->insert(applicationLifecycleMessage->getApplicationIdentifier(), applicationLifecycleMessage);
						}
						else if (applicationMessage.getMessageType() == ApplicationMessage::ApplicationMessagePayload)
						{
							shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage(new ApplicationPayloadMessage(message));
							smartNosClient->insert(applicationPayloadMessage->getApplicationIdentifier(), applicationPayloadMessage);
						}
						else 
						{
							cout << "Received unsupported application message: " << endl << message << endl;
						}
					}
				}
			}
		}
	}
}


SmartNosClient* SmartNosClient::instance = 0;

SmartNosClient* SmartNosClient::getInstance()
{
	if (!instance)
	{
		instance = new SmartNosClient();
	}

	return instance;
}

SmartNosClient::SmartNosClient() :
subscriptionSocketHostName("localhost"), subscriptionSocketPortNumber(4444), stopRunning(false)
{
	start();
}

SmartNosClient::~SmartNosClient()
{
	//wait for pthread_exit at some point
}

void SmartNosClient::start()
{
	//start watch thread
	pthread_t thread;
	int status;
	status = pthread_create(&thread, NULL, watch, (void *)(this));

	if (status)
	{
		cout << "ERROR: return code from pthread_create() is : " << status;
		exit(-1);
	}
   
}

void SmartNosClient::subscribe(const SmartNosApplication* smartNosApplication)
{
	//connect to SmartNOS subcriptionSocket
	try
	{
		DomainClientSocket subscriptionSocketClient(subscriptionSocketHostName, subscriptionSocketPortNumber);

		//send subscription message
		ClientSubscriptionMessage clientSubscriptionMessage(smartNosApplication);
		subscriptionSocketClient << clientSubscriptionMessage.getMessage();
	}
	catch (DomainSocketException& exc)
	{
		cout << "Caught Exception: " << exc.description() << endl; 
	}
	
}

void SmartNosClient::unsubscribe(const SmartNosApplication* smartNosApplication)
{
	//connect to SmartNOS subcriptionSocket
	DomainClientSocket subscriptionSocketClient(subscriptionSocketHostName, subscriptionSocketPortNumber);

	//send subscription message
	ClientSubscriptionMessage clientSubscriptionMessage(smartNosApplication);

	subscriptionSocketClient << clientSubscriptionMessage.getMessage();
}

void SmartNosClient::publishReport(const string& report)
{
	cout << "Publishing : " << report << " to SmartNos" << endl;
}

void SmartNosClient::getMessages(const string& applicationIdentifier, vector<shared_ptr<ApplicationMessage> >& applicationMessages)
{
	pair<MessageContainer::iterator, MessageContainer::iterator> range;
	do 
	{
		range = messages.equal_range(applicationIdentifier);
		if (range.first != range.second)
		{
			for (MessageContainer::iterator iter = range.first; iter != range.second; ++iter)
			{
				applicationMessages.push_back(iter->second);
			}
		}
		else
		{
			//would be a wait at some point
			sleep(5);
		}
	} while (!applicationMessages.size());

	//clear set for now
	messages.clear();
}

void SmartNosClient::insert(const std::string& applicationIdentifier, shared_ptr<ApplicationMessage> applicationMessage)
{
	messages.insert(make_pair(applicationIdentifier, applicationMessage));
}

