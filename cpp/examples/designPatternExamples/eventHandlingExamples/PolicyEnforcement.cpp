#include "PolicyEnforcement.hpp"
#include "PolicyEnforcementEngine.hpp"



PolicyEnforcement::PolicyEnforcement(const string& name, const string& source, int freq, const DateAndTime& start, const DateAndTime& end) : name(name), source(source), freq(freq), start(start), end(end)
{
}


PolicyEnforcement::~PolicyEnforcement()
{
}

string PolicyEnforcement::getName() const
{
	return name;
}

bool PolicyEnforcement::operator<(const PolicyEnforcement& rhs) const
{
	return start<rhs.getStart();
}

void PolicyEnforcement::setFreq(int f)
{
	freq = f;
}

void PolicyEnforcement::setStart(const DateAndTime& dt)
{
	start = dt;
}
	
void PolicyEnforcement::setEnd(const DateAndTime& dt)
{
	end = dt;
}


int PolicyEnforcement::getFreq() const
{
	return freq;
}

const DateAndTime& PolicyEnforcement::getStart() const
{
	return start;
}

const DateAndTime& PolicyEnforcement::getEnd() const
{
	return end;
}

void PolicyEnforcement::run()
{
	DateAndTime currentTime;
	cout << "PolicyEnforcement::run() -- '" << name << "' running at: " << currentTime << endl;
	
	if ( currentTime < end )
	{
		start.operator+(freq);
		cout << "PolicyEnforcement::update() -- '" << name << "' resubmitting policy with new start time: " << start << endl;
		PolicyEnforcementEngine::getInstance()->add(this);
	}
}
