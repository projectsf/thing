#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <string>
#include <ostream>

using namespace std;



class DateAndTime
{
	public:
		
		DateAndTime();
		DateAndTime(string);
		string getDateAndTime() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getHour() const;
		int getMinute() const;
		int getSecond() const;
	
		bool operator<(const DateAndTime&) const;
		bool operator>(const DateAndTime&) const;
		bool operator==(const DateAndTime&) const;
		bool operator<=(const DateAndTime&) const;
		bool operator>=(const DateAndTime&) const;
		void operator+(const DateAndTime&);
		void operator+(int);
		void operator-(const DateAndTime&);
		DateAndTime& operator=(const DateAndTime&);
		int toSeconds() const;
		void update();
		
	protected:
		DateAndTime(int year, int month, int day, int hour, int minute, int second);
		
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
