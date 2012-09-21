#include <string>


int main()
{
	//startup smartnos
	SmartNos smartNos;
	smartNos.start();

	//start up meter reader app
	MeterBillingDataReader meterBillingDataReader;
	meterBillingDataReader.start();

	//handle SIG-INT for close
	meteringBillingDataReader.stop();
	smartNos.stop();
};

