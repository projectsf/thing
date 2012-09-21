#include "./include/ApplicationEnforcementScheduler.hpp"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/lexical_cast.hpp>
#include "./include/SmartNosApplication.hpp"

using namespace std;
using namespace boost;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;

void *dispatch(void *opaque)
{
	ApplicationEnforcementScheduler* applicationEnforcementScheduler;
	applicationEnforcementScheduler = reinterpret_cast<ApplicationEnforcementScheduler*>(opaque);
	applicationEnforcementScheduler->enforce();
}

ApplicationEnforcementScheduler::ApplicationEnforcementScheduler(SmartNosApplication* smartNosApplication, const string& schedule) :
smartNosApplication(smartNosApplication), period(0), scheduleType(Unknown), done(false)
{
    //convert string to stringstream
    istringstream iss(schedule);
   
    //read in to property tree
    read_xml(iss, this->schedule, trim_whitespace);
}

void ApplicationEnforcementScheduler::run()
{
	
	//two cases, one periodic, one now
	try
	{
		ptree periodic = schedule.get_child("ApplicationPayload.Schedule.Periodic");
		scheduleType = Periodic;
		period = schedule.get<unsigned int>("ApplicationPayload.Schedule.Periodic.Period");
		
		//start periodic thread
		pthread_t thread;
		int status;
		status = pthread_create(&thread, NULL, dispatch, (void *)this);

		if (status)
		{
			cout << "ERROR: return code from pthread_create() for periodic thread is : " << status;
			exit(-1);
		}
	}
	catch(ptree_bad_path& exc)
	{
	}

	//one time
	try
	{
		ptree once = schedule.get_child("ApplicationPayload.Schedule.Once");
		scheduleType = OneTime;
		string when = once.get<string>("When");

		if ("NOW" == when)
		{
		
			//start periodic thread
			pthread_t thread;
			int status;
			status = pthread_create(&thread, NULL, dispatch, (void *)this);

			if (status)
			{
				cout << "ERROR: return code from pthread_create() is : " << status;
				exit(-1);
			}
		}
		else
		{
			cout << "Unsupported OneTime schedule: " << when << endl;
		}
	}
	catch(ptree_bad_path& exc)
	{
	}

	do 
	{
		//check for done every 5 seconds
		sleep(5);
	}
	while (!done);
	
}

void ApplicationEnforcementScheduler::enforce()
{
	if (Periodic == scheduleType)
	{
		cout << "Enforcing periodic schedule every " << period << " seconds" << endl;
		while (true)
		{
			smartNosApplication->enforce();
			sleep(period);
		}
	}
	else if (OneTime == scheduleType)
	{
		cout << "Enforcing one time schedule now" << endl;
		smartNosApplication->enforce();
	}
	else
	{
		cout << "Unknown schedule type" << endl;
	}

	done = true;
}
