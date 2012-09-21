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

using namespace std;

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

int main(int argc, char *argv[])
{
	//set some flags
	bool useLocal = true;
	bool dontUseLocal = false;

	//simulated UI input of 
	string deviceLocalTimeStringServer("2010-01-13T00:00:00");

	cout << "Desired Local Time: " << deviceLocalTimeStringServer << endl;

	//assume value is UTC and derive epoch seconds
	time_t deviceLocalTimeValueCommon= toTime(deviceLocalTimeStringServer, dontUseLocal);

	//convert to timestring assuming UTC
	std::string deviceLocalTimeString = toString(deviceLocalTimeValueCommon, dontUseLocal);

	//convert deviceLocalTimeString to epoch seconds assuming timestring is a local time
	time_t utcTimeValue = toTime(deviceLocalTimeString, useLocal);

	//execute at this time
	cout << "Derived Local Time: " << toString(utcTimeValue, useLocal) << endl;
}
