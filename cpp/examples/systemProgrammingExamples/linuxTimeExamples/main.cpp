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
#include <boost/lexical_cast.hpp>
#include <set>

using namespace std;
using namespace boost;

//
// Function outputs a string representation of time based on the epochSeconds input
// The returned string represents local time if isLocal = true, and a UTC string
// if isLocal = false
//
string toString(time_t epochSeconds, bool useLocal = true)
{
	char buffer[80];
	
	struct tm timeinfo;
	
	if (useLocal)
	{
		localtime_r ( &epochSeconds,&timeinfo );
		strftime (buffer,80,"%Y-%m-%dT%H:%M:%S",&timeinfo);
		return string(buffer);
	}
	else
	{
		gmtime_r ( &epochSeconds,&timeinfo );
		strftime (buffer,80,"%Y-%m-%dT%H:%M:%S",&timeinfo);
		return string(buffer);
	}
}

//
// Function takes a string representation of date and time and returns epochSeconds
// dateAndTime is interpreted as a local string if isLocal = true, and a UTC string
// if isLocal = false
//
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

//
// Function takes a broken down representation of date and time and returns epochSeconds
//
time_t toTime(int year, int month, int day, int hour, int minute, int second, bool isLocal = true)
{
	if (isLocal)
	{
		//initialize timeinfo struct and set tm_isdst to -1
		tm timeinfo; 
		memset(&timeinfo, 0, sizeof(timeinfo));
		timeinfo.tm_isdst = -1;
	
		//populate tm struct object
		timeinfo.tm_year = year - 1900;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_mday = day;
		timeinfo.tm_hour = hour;
		timeinfo.tm_min = minute;
		timeinfo.tm_sec = second;
		timeinfo.tm_isdst = -1;

		return mktime(&timeinfo);
	}
	else
	{
		//initialize timeinfo object
		tm timeinfo; 
		memset(&timeinfo, 0, sizeof(timeinfo));
	
		//populate tm struct object
		timeinfo.tm_year = year - 1900;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_mday = day;
		timeinfo.tm_hour = hour;
		timeinfo.tm_min = minute;
		timeinfo.tm_sec = second;
		
		return timegm(&timeinfo);
	}
}


time_t getNextInterval(time_t epochSeconds, unsigned int period)
{
		const unsigned int SecondsInMinute = 60;
		const unsigned int MinutesInHour = 60;
		//extract timezone offset
    tm timeinfo;
    localtime_r(&epochSeconds, &timeinfo);
		cout << "timezone offset: " << timeinfo.tm_gmtoff << endl;

    //round current time to nearest hour adjusting for timezone offset
		unsigned int epochHours = (epochSeconds + timeinfo.tm_gmtoff) / SecondsInMinute / MinutesInHour;

 
    //calculate next boundary of numberMinutes
    unsigned int adjustedEpochHours = epochHours - epochHours % (period/60) + (period/60);
   
    //return difference between next occurrence of minute boundary and current time adjusting for tz
		return adjustedEpochHours * MinutesInHour * SecondsInMinute - timeinfo.tm_gmtoff;

}


int main(int argc, char *argv[])
{
	std::set<unsigned int> frequencies;
	//frequencies.insert(1);
	//frequencies.insert(2);
	//frequencies.insert(3);
	//frequencies.insert(4);
	frequencies.insert(6);
	//frequencies.insert(8);
	//frequencies.insert(12);
	for (set<unsigned int>::iterator iter = frequencies.begin(); iter != frequencies.end(); ++iter)
	{
		unsigned int frequency = *iter * 60;
		cout << "Freq = " << lexical_cast<string>(frequency) << endl;
		const unsigned int NumberHours = 24;
		for (unsigned int ii = 0; ii < NumberHours; ++ii)
		{
			string hour = ii >= 10 ?  lexical_cast<string>(ii) : "0" + lexical_cast<string>(ii);
			string dateAndTime("2011-03-22T" + hour + ":43:00");
			cout << "DT:" << dateAndTime << "\t" << "NI: " << toString(getNextInterval(toTime(dateAndTime, 1), frequency), 1) << endl;
		}
	}
}
