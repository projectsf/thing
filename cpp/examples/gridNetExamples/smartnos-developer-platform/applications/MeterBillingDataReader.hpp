#ifndef METER_BILLING_DATA_READER_HPP_
#define METER_BILLING_DATA_READER_HPP_


#include <string>
#include "../smartnosapplicationframework/include/ApplicationMessage.hpp"
#include "../smartnosapplicationframework/include/SmartNosPolicyApplication.hpp"
#include <boost/shared_ptr.hpp>


class MeterBillingDataReader : public SmartNosPolicyApplication
{
	public :
		MeterBillingDataReader();
		void enforce();

	protected :
		virtual void handleApplicationPayloadMessage(boost::shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage);
};

#endif
