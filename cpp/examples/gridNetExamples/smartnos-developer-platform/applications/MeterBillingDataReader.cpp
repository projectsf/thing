#include "MeterBillingDataReader.hpp"
#include <string>
#include "../smartnosapplicationframework/include/ApplicationEnforcementScheduler.hpp"
#include "../smartnosapplicationframework/include/MeteringServiceClient.hpp"
#include "../smartnosapplicationframework/include/SmartNosClient.hpp"

using namespace std;
using namespace boost;

MeterBillingDataReader::MeterBillingDataReader() :
	SmartNosPolicyApplication("MeterBillingDataReader-v.0.1", "MeteringPolicy")
{
}

void MeterBillingDataReader::handleApplicationPayloadMessage(shared_ptr<ApplicationPayloadMessage> applicationPayloadMessage)
{
	cout << applicationIdentifier << " is handling new application payload message" << endl;
	ApplicationEnforcementScheduler scheduler(this, applicationPayloadMessage->getMessage());
	scheduler.run();
}

void MeterBillingDataReader::enforce()
{
	if (!stopRunning)
	{
		//use metering client to get metering data
		MeteringServiceClient meteringServiceClient;
		string meteringServiceBillingData;
		meteringServiceClient.getBillingData(meteringServiceBillingData);

		//publish metering data back to smartnos
		SmartNosClient::getInstance()->publishReport(meteringServiceBillingData);
	}
}
