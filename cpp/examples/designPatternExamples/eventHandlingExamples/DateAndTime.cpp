#include "DateAndTime.hpp"
#include "boost/lexical_cast.hpp"
#include <time.h>
#include <unistd.h>
#include <syscall.h>
#include <sys/time.h>
#include <iostream>

using namespace std;
using namespace boost;

ostream& operator<<(ostream& os, const DateAndTime& rhs)
{
	os << rhs.getDateAndTime();
	return os;
}

DateAndTime::DateAndTime()
{
	timeval tv;
	tm* a_tm;
	gettimeofday(&tv,NULL);
	a_tm = localtime(&tv.tv_sec);
	year = a_tm->tm_year + 1900;
	month = a_tm->tm_mon + 1;
	day = a_tm->tm_mday;
	hour = a_tm->tm_hour;
	minute = a_tm->tm_min;
	second = a_tm->tm_sec;
}

DateAndTime::DateAndTime(int year, int month, int day, int hour, int minute, int second)
	: year(year), month(month), day(day), hour(hour), minute(minute), second(second)
{
}

bool DateAndTime::operator==(const DateAndTime& rhs) const
{
	return ( year == rhs.getYear() && month == rhs.getMonth() &&  day == rhs.getDay() && hour == rhs.getHour() && minute == rhs.getMinute() && second == rhs.getSecond());
}

DateAndTime& DateAndTime::operator=(const DateAndTime& rhs)
{
	second = rhs.getSecond();
	minute = rhs.getMinute();
	hour = rhs.getHour();
	day = rhs.getDay();
	month = rhs.getMonth();
	year = rhs.getYear();
	return *this;
}


bool DateAndTime::operator<(const DateAndTime& rhs) const
{
	if ( year < rhs.getYear() )
		return true;
	else if (month < rhs.getMonth() )
		return true;
	else if (day < rhs.getDay() )
		return true;
	else if (hour < rhs.getHour() )
		return true;
	else if (minute < rhs.getMinute() )
		return true;
	else if (second < rhs.getSecond() )
		return true;
	else
		return false;
}

void DateAndTime::operator+(const DateAndTime& rhs)
{
	int sum = 0;
	int overflow = 0;
	int secondMax = 60;
	int minuteMax = 60;
	int hourMax = 24;
	int dayMax = 30;
	int monthMax = 12;
	int yearMax = 2038;
	
	//seconds
	sum = second + rhs.getSecond();
	overflow = sum > secondMax;
	second = (overflow ? sum - secondMax : sum);
	
	//minutes
	sum = (overflow ? minute + rhs.getMinute() + 1 : minute + rhs.getMinute() );
	overflow = sum > minuteMax;
	minute = (overflow ? sum - minuteMax : sum);
	
	//hours
	sum = (overflow ? hour + rhs.getHour() + 1 : hour + rhs.getHour() );
	overflow = sum > hourMax;
	hour = (overflow ? sum - hourMax : sum);
	
	//days
	sum = (overflow ? day + rhs.getDay() + 1 : day + rhs.getDay() );
	overflow = sum > dayMax;
	day = (overflow ? sum - dayMax : sum);
	
	//months
	sum = (overflow ? month + rhs.getMonth() + 1 : month + rhs.getMonth() );
	overflow = sum > monthMax;
	month = (overflow ? sum - monthMax : sum);
	
	//years
	sum = (overflow ? year + rhs.getYear() + 1 : year + rhs.getYear() );
	overflow = sum > yearMax;
	year = (overflow ? sum - yearMax : sum);
	
}

void DateAndTime::operator+(int seconds)
{
	DateAndTime offset(0, 0, 0, 0, seconds/60, seconds%60);
	operator+(offset);
}


int DateAndTime::getYear() const
{
	return year;
}

int DateAndTime::getMonth() const
{
	return month;
}

int DateAndTime::getDay() const
{
	return day;
}

int DateAndTime::getHour() const
{
	return hour;
}

int DateAndTime::getMinute() const
{
	return minute;
}

int DateAndTime::getSecond() const
{
	return second;
}

void DateAndTime::update()
{
	timeval tv;
	tm* a_tm;
	gettimeofday(&tv,NULL);
	a_tm = localtime(&tv.tv_sec);
	year = a_tm->tm_year + 1900;
	month = a_tm->tm_mon + 1;
	day = a_tm->tm_mday;
	hour = a_tm->tm_hour;
	minute = a_tm->tm_min;
	second = a_tm->tm_sec;
}

string DateAndTime::getDateAndTime() const
{
	string temp;
	temp = lexical_cast<string>(year) + ":" + lexical_cast<string>(month) + ":" + lexical_cast<string>(day) + "T" + lexical_cast<string>(hour) + ":" + lexical_cast<string>(minute) + ":" + lexical_cast<string>(second);
	return temp;
}
