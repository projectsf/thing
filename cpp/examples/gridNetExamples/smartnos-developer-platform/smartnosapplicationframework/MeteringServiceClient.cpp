#include "./include/MeteringServiceClient.hpp"
#include <fstream>
#include <sstream>

using namespace std;

MeteringServiceClient::MeteringServiceClient() :
billingDataFileName("./input/billingData.xml")
{
}

void MeteringServiceClient::getBillingData(string& billingData)
{
	billingData += "<PowerQualityProfile><UtilitySerialNumber>SAMPLE19</UtilitySerialNumber> <Entry> <ReadTime>2012-05-25T12:00:00</ReadTime> <Element> <ElementIdentifier>1</ElementIdentifier> <Phase> <PhaseIdentifier>Aggregate</PhaseIdentifier> <Voltage>119.23</Voltage> <Current>89.23</Current> <PowerFactor> <Value>100.0</Value> <Quadrant>Q4</Quadrant> </PowerFactor> </Phase> ";
}
