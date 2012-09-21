#ifndef POLICYENFORCEMENT_HPP_
#define POLICYENFORCEMENT_HPP_

#include "DateAndTime.hpp"
#include <string>
#include <iostream>

using namespace std;


class PolicyEnforcement
{
	public:
		PolicyEnforcement(const string&, const string&, int, const DateAndTime&, const DateAndTime&);
		virtual ~PolicyEnforcement();
		string getName() const;
		int getFreq() const;
		void setFreq(int);
		void setStart(const DateAndTime&);
		void setEnd(const DateAndTime&);
		const DateAndTime& getStart() const;
		const DateAndTime& getEnd() const;
		bool operator<(const PolicyEnforcement& rhs) const;
		virtual void run();
		
	protected:
		string name;
		string source;
		int freq; 
		DateAndTime start; 
		DateAndTime end;

};

#endif /*POLICYENFORCEMENT_HPP_*/
