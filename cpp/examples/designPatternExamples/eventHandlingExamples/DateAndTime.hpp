#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <string>
#include <ostream>

using namespace std;


template<class T> 
bool operator!=(const T& lhs, const T& rhs) 
{
	return !(lhs == rhs);
} 

template<class T> 
bool operator>(const T& lhs, const T& rhs) 
{
	return (rhs < lhs);
} 

template<class T> 
bool operator<=(const T& lhs, const T& rhs) 
{
	return !(rhs < lhs);
} 

template<class T> 
bool operator>=(const T& lhs,const T& rhs) 
{
	return !(lhs < rhs);
}

class DateAndTime
{
	public:
		
		DateAndTime();
		DateAndTime(int year, int month, int day, int hour, int minute, int second);
		DateAndTime& operator=(const DateAndTime&);
		bool operator<(const DateAndTime&) const;
		bool operator==(const DateAndTime&) const;
		void operator+(const DateAndTime&);
		void operator+(int);
		string getDateAndTime() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getHour() const;
		int getMinute() const;
		int getSecond() const;
		void update();
		
	private:
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
};

ostream& operator<<(ostream&, const DateAndTime&);

#endif
