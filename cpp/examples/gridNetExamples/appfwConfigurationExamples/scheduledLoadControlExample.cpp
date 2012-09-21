
#include <appfw/Configuration.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace appfw;
using namespace boost;

enum SwitchAction { TurnSwitchOn, TurnSwitchOff };

class SecondarySwitchScheduleEntry
{
	public:
		explicit SecondarySwitchScheduleEntry(string actionTimeOfDay, SwitchAction action) : 
		actionTimeOfDay(actionTimeOfDay), action(action)
		{
		}
		
		string toString() const
		{
			string str;
			str += "ActionTimeOfDay: " + actionTimeOfDay + "\n";
			str += "SwitchAction: " + lexical_cast<string>(static_cast<unsigned int>(action)) + "\n";
			return str;
		}
		
	private:
		string actionTimeOfDay;
		SwitchAction action;
};



int main(int argc, char *argv[])
{
	const unsigned int NUM_WEEKDAY_SETS = 5;
	const unsigned int NUM_WEEKEND_SETS = 5;


	/* containers for test data */
	vector<string> actionTimeOfDays(NUM_WEEKDAY_SETS);
	
	/* generate some price and duration data */
	for (unsigned int ii = 0; ii < NUM_WEEKDAY_SETS; ++ii)
	{
		actionTimeOfDays[ii] = "12:30";
	}
	
	/* build configuration */
	ConfigurationList scheduleSets("schedule-sets");
	
	Configuration* section = new ConfigurationList("weekday-sets");
	Configuration* nestedSection;
	for (unsigned int ii = (NUM_WEEKDAY_SETS - 1) ; ii > 0; --ii)
	{
		nestedSection = new ConfigurationList("set-" + lexical_cast<string>(ii));
		Configuration* value = new ConfigurationValue("turn-on", lexical_cast<string>(actionTimeOfDays[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("turn-off", lexical_cast<string>(actionTimeOfDays[ii]));
		nestedSection->add(value);
		section->add(nestedSection);
	}
	scheduleSets.add(section);
	
	section = new ConfigurationList("weekend-sets");
	for (unsigned int ii = (NUM_WEEKDAY_SETS - 1) ; ii > 0; --ii)
	{
		nestedSection = new ConfigurationList("set-" + lexical_cast<string>(ii));
		Configuration* value = new ConfigurationValue("turn-on", lexical_cast<string>(actionTimeOfDays[ii]));
		nestedSection->add(value);
		value = new ConfigurationValue("turn-off", lexical_cast<string>(actionTimeOfDays[ii]));
		nestedSection->add(value);
		section->add(nestedSection);
	}
	scheduleSets.add(section);
	
	ostringstream output;
	scheduleSets.store(output, 1);
	cout << output.str() << endl;
	
	/* try to it the other way */
	vector<SecondarySwitchScheduleEntry> scheduleSetEntries;
	istringstream input(output.str());
	Configuration* config = Configuration::load(input);
	Configuration* configList = config->get("schedule-sets");

	//get weekday sets
	Configuration* weekdaySets = configList->get("weekday-sets");
	unsigned int count = 1;
	for (Configuration::ConfigurationListIterator iter = weekdaySets->begin(); iter != weekdaySets->end(); ++iter, ++count)
	{
		string turnOnTimeOfDay = (*iter)->getProperty<string>("turn-on");
		scheduleSetEntries.push_back(SecondarySwitchScheduleEntry(turnOnTimeOfDay, TurnSwitchOn));
		string turnOffTimeOfDay = (*iter)->getProperty<string>("turn-off");
		scheduleSetEntries.push_back(SecondarySwitchScheduleEntry(turnOffTimeOfDay, TurnSwitchOff));
	}
	
	for (vector<SecondarySwitchScheduleEntry>::const_iterator iter = scheduleSetEntries.begin(); iter != scheduleSetEntries.end(); ++iter)
	{
		cout << iter->toString();
	}

	
	delete config;
	
	return 0;
}
