#include "SmartNos.hpp"
#include <iostream>
#include <fstream>
#include "../smartnosapplicationframework/ClientSubscriptionMessage.hpp"
#include "../smartnosapplicationframework/DomainSocketException.hpp"
#include <sys/select.h>
#include <algorithm>

using namespace std;
using namespace boost;

SmartNos::SmartNos() :
subscriptionServerSocket(4444), stopRunning(false)
{
}

SmartNos::~SmartNos()
{
}

void SmartNos::start()
{
	cout << "Starting SmartNOS" << endl;
	watch();
}

void SmartNos::stop()
{
	//send stops to all applications
	cout << "Stopping SmartNOS" << endl;
}
	
void SmartNos::watch()
{
	fd_set read_fds;
	fd_set active_fds;
	FD_ZERO(&active_fds);
	FD_SET(subscriptionServerSocket.getSocketFd(), &active_fds);
	unsigned int fdMax = subscriptionServerSocket.getSocketFd() + 1; 

	while (!stopRunning)
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
					if (subscriptionServerSocket.getSocketFd() == ii)
					{
						string message;
						try 
						{
							DomainServerSocket new_sock;
							subscriptionServerSocket.accept ( new_sock );

							new_sock >> message;


						}
						catch (DomainSocketException& exc)
						{
							cout << "Caught exception: " << exc.description() << endl;
						}

						ClientSubscriptionMessage clientSubscriptionMessage(message);
						cout << "Received application registration message from: " << clientSubscriptionMessage.getApplicationIdentifier() << endl;

						//pass to handler
						handleSubscriptionMessage(clientSubscriptionMessage);
					}
				}
			}
		}
	}
}

void SmartNos::handleSubscriptionMessage(const ClientSubscriptionMessage& clientSubscriptionMessage)
{
	if (ClientSubscriptionMessage::Subscribe == clientSubscriptionMessage.getAction())
	{
		applications.insert(make_pair(clientSubscriptionMessage.getApplicationIdentifier(), clientSubscriptionMessage.getClassIdentifier()));
	}
	else if (ClientSubscriptionMessage::Unsubscribe == clientSubscriptionMessage.getAction())
	{
	}
}
