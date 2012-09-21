#ifndef SMART_NOS_CLIENT_HPP_
#define SMART_NOS_CLIENT_HPP_

#include <string>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include "SmartNosApplication.hpp"
#include "ApplicationMessage.hpp"
#include "../DomainServerSocket.hpp"

class SmartNosClient
{
	public :
        typedef std::multimap<std::string, boost::shared_ptr<ApplicationMessage> > MessageContainer;
		~SmartNosClient();
		static SmartNosClient* getInstance();
		void subscribe(const SmartNosApplication* smartNosApplication);
		void unsubscribe(const SmartNosApplication* smartNosApplication);
		void getMessages(const std::string& applicationName, std::vector<boost::shared_ptr<ApplicationMessage> >& messages);
		void publishReport(const std::string& report);
		void insert(const std::string& applicationIdentifier, boost::shared_ptr<ApplicationMessage> applicationMessage);

	private :
		SmartNosClient();
		static SmartNosClient* instance;
		void start();
        MessageContainer messages;
		const std::string subscriptionSocketHostName;
		const unsigned int subscriptionSocketPortNumber;
		bool stopRunning;
};

#endif
