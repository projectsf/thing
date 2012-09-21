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


int main(int argc, char *argv[])
{
	string dateAndTime("2010-01-13T00:00:00Z");
	string dateAndTimeTwo("2009-11-24T09:23:19");
	cout << toTime(dateAndTime, 1) << endl;
	cout << toTime(dateAndTimeTwo, 1) << endl;

}
