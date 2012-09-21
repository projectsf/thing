
#include <appfw/Configuration.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace appfw;
using namespace boost;





int main(int argc, char *argv[])
{
	const unsigned int NUM_CHANNELS = 5;


	/* containers for test data */
	vector<string> uoms(NUM_CHANNELS);
	vector<string> timebases(NUM_CHANNELS);
	vector<string> multipliers(NUM_CHANNELS);
	vector<string> divisors(NUM_CHANNELS);
	vector<string> scalars(NUM_CHANNELS);
	vector<string> sourceIds(NUM_CHANNELS);
	
	/* generate some price and duration data */
	for (unsigned int ii = 0; ii < NUM_CHANNELS; ++ii)
	{
		uoms[ii] = lexical_cast<string>(ii);
		timebases[ii] = lexical_cast<string>(ii);
		multipliers[ii] = lexical_cast<string>(ii);
		divisors[ii] = lexical_cast<string>(ii);
		scalars[ii] = lexical_cast<string>(ii);
		sourceIds[ii] = lexical_cast<string>(ii);
	}


	/* build configuration */
	ConfigurationList metaData("meta-data");
	
	
	Configuration* channelMetaData = new ConfigurationList("chan-meta-data");
	Configuration* nestedSection;
	for (int ii = (NUM_CHANNELS - 1) ; ii >= 0; --ii)
	{
		nestedSection = new ConfigurationList("chan-" + lexical_cast<string>(ii));
		Configuration* value = new ConfigurationValue("uom", lexical_cast<string>(uoms[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("timebase", lexical_cast<string>(timebases[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("multiplier", lexical_cast<string>(multipliers[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("divisor", lexical_cast<string>(divisors[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("scalar", lexical_cast<string>(scalars[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("source-id", lexical_cast<string>(sourceIds[ii]));
		nestedSection->add(value);
		channelMetaData->add(nestedSection);
	}
	metaData.add(channelMetaData);
	
	//add scalar attributes
	Configuration* numberValidBlocks = new ConfigurationValue("number-valid-blocks", "50");
	Configuration* numberIntervalsLastBlock = new ConfigurationValue("number-intervals-last-block", "32");
	Configuration* numberIntervalsPerBlock = new ConfigurationValue("number-intervals-per-block", "96");
	
	metaData.add(numberValidBlocks);
	metaData.add(numberIntervalsLastBlock);
	metaData.add(numberIntervalsPerBlock);
	
	
	ostringstream output;
	metaData.store(output, 1);
	cout << output.str() << endl;
	
	
	return 0;
}
