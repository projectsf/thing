#ifndef POLICYENFORCEMENTSOURCE_H
#define POLICYENFORCEMENTSOURCE_H

#include <string>
#include <vector>
#include "PolicyEnforcement.hpp"

using namespace std;

class PolicyEnforcementSource
{
	public:
		PolicyEnforcementSource(string);
		~PolicyEnforcementSource();
		void run();
		string getName() const;
	protected:
		string name;
		vector<PolicyEnforcement* > policyEnforcements;

};
#endif
