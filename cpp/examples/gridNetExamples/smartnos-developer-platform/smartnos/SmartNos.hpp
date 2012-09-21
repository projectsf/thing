#ifndef SMART_NOS_HPP_
#define SMART_NOS_HPP_

#include <string>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "../smartnosapplicationframework/ClientSubscriptionMessage.hpp"
#include "../smartnosapplicationframework/include/ApplicationMessage.hpp"
#include "../smartnosapplicationframework/DomainServerSocket.hpp"

class SmartNos
{
	public :
		typedef std::map<std::string, std::string> ApplicationContainer;
 		SmartNos();
 		~SmartNos();
		void start();
		void stop();

	private:
		void watch();
		void handleSubscriptionMessage(const ClientSubscriptionMessage& clientSubscriptionMessage);
		ApplicationContainer applications;
		DomainServerSocket  subscriptionServerSocket;
		bool stopRunning;
};

#endif //SMART_NOS_HPP_
