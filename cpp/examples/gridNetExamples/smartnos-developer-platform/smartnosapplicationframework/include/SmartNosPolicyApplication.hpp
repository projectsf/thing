#ifndef SMART_NOS_POLICY_APPLICATION_HPP_
#define SMART_NOS_POLICY_APPLICATION_HPP_

#include <string>
#include "SmartNosApplication.hpp"
#include <boost/shared_ptr.hpp>

class SmartNosPolicyApplication : public SmartNosApplication
{
	public :
		SmartNosPolicyApplication(std::string applicationName, std::string classIdentifier);

		virtual void handleApplicationPayloadMessage(boost::shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage) = 0;
		virtual void enforce() = 0;

	protected : 
		bool stopRunning;

	private :
		std::string classIdentifier;

};

#endif
