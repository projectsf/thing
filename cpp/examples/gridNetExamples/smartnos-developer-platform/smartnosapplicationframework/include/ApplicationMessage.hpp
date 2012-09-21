#ifndef APPLICATION_MESSAGE_HPP_
#define APPLICATION_MESSAGE_HPP_

#include <string>
#include <boost/property_tree/ptree.hpp>

class ApplicationMessage
{
	public :
		enum MessageType
		{
			ApplicationLifecycle,
			ApplicationMessagePayload,
			Unknown
		};
		ApplicationMessage(const std::string& message);
		virtual std::string getApplicationIdentifier() const;
		MessageType getMessageType() const;
		std::string getMessage() const;
	protected:
		boost::property_tree::ptree message;
};

class ApplicationPayloadMessage : public ApplicationMessage
{
	public :
		ApplicationPayloadMessage(const std::string& message);
		std::string getApplicationIdentifier() const;
};

class ApplicationLifecycleMessage : public ApplicationMessage
{
	public :
		enum Action
		{
			Start,
			Stop,
			Unknown
		};
		ApplicationLifecycleMessage(const std::string& message);
		std::string getApplicationIdentifier() const;
		Action getAction() const;
};

#endif //APPLICATION_MESSAGE_HPP_
