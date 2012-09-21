/**
 * Example looks at unix system time
 *
 * @file unixTimeExample.cpp
 */
 
#include <time.h>
#include <unistd.h>
#include <syscall.h>
#include <sys/time.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

time_t toTime(const string& dateAndTime, bool isLocal = true)
{
    if (isLocal)
    {
        //initialize timeinfo struct and set tm_isdst to -1
        char* ret;
        tm timeinfo;
        memset(&timeinfo, 0, sizeof(timeinfo));
        timeinfo.tm_isdst = -1;

        ret = strptime(dateAndTime.c_str(), "%Y-%m-%dT%H:%M:%S%Z", &timeinfo);


        if (ret == NULL)
        {
            cerr << "Error with " << dateAndTime << endl;
        }

        else if (*ret != '\0')
        {
            cerr << "Error not completed : " << dateAndTime << endl;
        }

        return mktime(&timeinfo);
    }
    else
    {
        //initialize timeinfo struct
        tm timeinfo;
        memset(&timeinfo, 0, sizeof(timeinfo));

        if ( !strptime(dateAndTime.c_str(), "%Y-%m-%dT%H:%M:%S%Z", &timeinfo) )
        {
            cerr << "Error" << endl;
        }

        return timegm(&timeinfo);
    }
}


bool isNewDay(const std::string& previousTime, const std::string& currentTime)
{
	//extract date from last connection attempt
	tm previousTimeInfo;
	tm currentTimeInfo;
	memset(&previousTimeInfo, 0, sizeof(previousTimeInfo));
	memset(&currentTimeInfo, 0, sizeof(currentTimeInfo));

	//create some times

	//get local time for previous and current
	time_t previousConnectionTimeEpochSeconds = toTime(previousTime);
	localtime_r(&previousConnectionTimeEpochSeconds, &previousTimeInfo);

	//get local time for previous and current
	time_t currentConnectionTimeEpochSeconds = toTime(currentTime);
	localtime_r(&currentConnectionTimeEpochSeconds, &currentTimeInfo);

	//zero out m/hr/sec and see if second is greater
	previousTimeInfo.tm_min = 0;
	previousTimeInfo.tm_sec = 0;

	currentTimeInfo.tm_min = 0;
	currentTimeInfo.tm_sec = 0;

	//convert back to time
	return mktime(&currentTimeInfo) > mktime(&previousTimeInfo);
}

int main()
{
    string previousDateAndTime("2010-01-11T02:00:00");
    string currentDateAndTime("2010-01-11T02:02:00");

	cout << "Previous: "  << previousDateAndTime << endl;
	cout << "Current: "  << currentDateAndTime << endl;
	cout << "Is new day: " << isNewDay(previousDateAndTime, currentDateAndTime) << endl;
}
