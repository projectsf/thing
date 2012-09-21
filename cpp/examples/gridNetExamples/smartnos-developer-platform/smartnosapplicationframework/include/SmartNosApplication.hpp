#ifndef SMART_NOS_APPLICATION_HPP
#define SMART_NOS_APPLICATION_HPP

#include <string>
#include "ApplicationMessage.hpp"
#include <boost/shared_ptr.hpp>

class SmartNosApplication
{
	public :
		SmartNosApplication(const std::string& applicationIdentifier);
		~SmartNosApplication();
		void run();
		const std::string& getApplicationIdentifier() const;
		virtual void handleApplicationPayloadMessage(boost::shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage) = 0;
		virtual void enforce() = 0;

	protected :
		std::string applicationIdentifier;
		bool stopRunning;

	private :
		void subscribe();
		void unsubscribe();
		void start();
		void stop();
		void handleApplicationMessage(boost::shared_ptr<ApplicationMessage> applicationMessage);
		bool isRunning;
};

#endif //SMART_NOS_APPLICATION_HPP
