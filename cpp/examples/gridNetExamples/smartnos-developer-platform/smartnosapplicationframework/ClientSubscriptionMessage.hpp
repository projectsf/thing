#ifndef CLIENT_SUBSCRIPTION_MESSAGE_HPP_
#define CLIENT_SUBSCRIPTION_MESSAGE_HPP_

#include <string>
#include <boost/property_tree/ptree.hpp>

class SmartNosApplication;
class ClientSubscriptionMessage
{
	public :
		enum Action
		{
			Subscribe,
			Unsubscribe,
			Unknown
		};

		ClientSubscriptionMessage(const std::string& message);
		ClientSubscriptionMessage(const SmartNosApplication* application);
		void unmarshall(const std::string& message);
		void marshall(std::string& message);
		std::string getApplicationIdentifier() const;
		std::string getClassIdentifier() const;
		Action getAction() const;
		std::string getMessage() const;
	private :
		boost::property_tree::ptree message;
};

#endif //CLIENT_SUBSCRIPTION_MESSAGE_HPP_
