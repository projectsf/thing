#ifndef APPLICATION_ENFORCEMENT_SCHEDULER_HPP_
#define APPLICATION_ENFORCEMENT_SCHEDULER_HPP_

#include <string>
#include <boost/property_tree/ptree.hpp>

class SmartNosApplication;
class ApplicationEnforcementScheduler
{
	public :
		enum ScheduleType
		{
			OneTime,
			Periodic,
			Unknown
		};
		ApplicationEnforcementScheduler(SmartNosApplication* smartNosApplication, const std::string& schedule);
		void run();
		void enforce();
	private :
		SmartNosApplication* smartNosApplication;
		ScheduleType scheduleType;
		unsigned int period;
		bool done;
		boost::property_tree::ptree schedule;
};

#endif //APPLICATION_ENFORCEMENT_SCHEDULER_HPP_
