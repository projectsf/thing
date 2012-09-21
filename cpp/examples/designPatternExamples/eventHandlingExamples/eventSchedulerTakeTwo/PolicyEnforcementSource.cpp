#include "PolicyEnforcementSource.hpp"
#include "PolicyEnforcementEngine.hpp"
#include "DateAndTime.hpp"


PolicyEnforcementSource::PolicyEnforcementSource(string name)
	: name(name)
{
		//Function params
	DateAndTime start;
	DateAndTime end;
	int startOffset;
	int endOffset;
	int freq;
	

	//PolicyEnforcementOne params
	startOffset = 10;
	start.operator+(startOffset);
	endOffset = 30;
	end.operator+(endOffset);
	freq = 2;
	policyEnforcements.push_back( new PolicyEnforcement("PolicyEnforcementOne", name, freq, start, end) );
	
	//PolicyEnforcementTwo params
	start.update();
	end.update();
	startOffset = 20;
	start.operator+(startOffset);
	endOffset = 30;
	end.operator+(endOffset);
	freq = 1;
	policyEnforcements.push_back( new PolicyEnforcement("PolicyEnforcementTwo", name, freq, start, end) );
		
}

PolicyEnforcementSource::~PolicyEnforcementSource()
{
	vector<PolicyEnforcement*>::iterator iter = policyEnforcements.begin();
	vector<PolicyEnforcement*>::iterator end = policyEnforcements.end();
	
	for( ; iter!=end; ++iter)
	{
		delete *iter;
	}
}

void PolicyEnforcementSource::run()
{
	vector<PolicyEnforcement*>::iterator iter = policyEnforcements.begin();
	vector<PolicyEnforcement*>::iterator end = policyEnforcements.end();
	
	for( ; iter!=end; ++iter)
	{
		PolicyEnforcementEngine::getInstance()->add((*iter));
	}

}

string PolicyEnforcementSource::getName() const
{
	return name;
}


