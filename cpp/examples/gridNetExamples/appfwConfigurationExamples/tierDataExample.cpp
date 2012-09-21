#include <appfw/Configuration.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace appfw;
using namespace boost;

class TierData
{
	public:
		explicit TierData(unsigned int tierId, float tierPrice, unsigned int tierDuration) : 
		tierId(tierId), tierPrice(tierPrice), tierDuration(tierDuration)
		{
		}
		
		string toString() const
		{
			string str;
			str += "TierId: " + appfw::lexical_cast<string>(tierId) + "\n";
			str += "TierPrice: " + appfw::lexical_cast<string>(tierPrice) + "\n";
			str += "TierDuration: " + appfw::lexical_cast<string>(tierDuration) + "\n";
			return str;
		}
		
	private:
		unsigned int tierId;
		float tierPrice;
		unsigned int tierDuration;
};



int main(int argc, char *argv[])
{
	const unsigned int NUM_TIERS = 5;

	/* containers for test data */
	vector<string> tierPrices(NUM_TIERS);
	vector<string> tierDurations(NUM_TIERS);
	
	/* generate some price and duration data */
	for (unsigned int ii = 0; ii < NUM_TIERS; ++ii)
	{
		tierPrices[ii] = appfw::lexical_cast<string>(ii * 3.34);
		tierDurations[ii] = appfw::lexical_cast<string>(ii * 9);
	}
	
	/* build configuration */
	ConfigurationList tierData("TierData");
	
	for (unsigned int ii = (NUM_TIERS - 1) ; ii > 0; --ii)
	{
		Configuration* section = new ConfigurationList("tier-" + appfw::lexical_cast<string>(ii));
		Configuration* value = new ConfigurationValue("tierDuration", appfw::lexical_cast<string>(tierDurations[ii]));
		section->add(value);
		value = new ConfigurationValue("tierPrice", appfw::lexical_cast<string>(tierPrices[ii]));
		section->add(value);
		value = new ConfigurationValue("tierId", appfw::lexical_cast<string>(ii));
		section->add(value);
		tierData.add(section);
	}
	
	ostringstream output;
	tierData.store(output, 1);
	cout << output.str() << endl;
	
	/* try to it the other way */
	vector<TierData> tierDatas;
	istringstream input(output.str());
	Configuration* config = Configuration::load(input);
	Configuration* configList = config->get("TierData");

	unsigned int count = 1;
	for (Configuration::ConfigurationListIterator ii = configList->begin(); ii != configList->end(); ++ii, ++count)
	{
				
		unsigned int tierId = (*ii)->getProperty<unsigned int>("tierId");
		float tierPrice = (*ii)->getProperty<float>("tierPrice");
		unsigned int tierDuration = (*ii)->getProperty<unsigned int>("tierDuration");
		tierDatas.push_back(TierData(tierId, tierPrice, tierDuration));
	}
	
	for (vector<TierData>::const_iterator iter = tierDatas.begin(); iter != tierDatas.end(); ++iter)
	{
		cout << iter->toString();
	}
	
	return 0;
}
