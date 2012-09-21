#ifndef POLICYENFORCEMENTENGINE_HPP
#define POLICYENFORCEMENTENGINE_HPP

#include <set>
#include "Thread.hpp"
#include "PolicyEnforcement.hpp"
#include <boost/thread/mutex.hpp>


using namespace std;


template<typename T>
class PointeeCompare
{
	public:
		bool operator()(const T& rhs, const T& lhs)
		{
			return *rhs < *lhs;
		}
};


class PolicyEnforcementEngine : public Runnable
{
	public:
		typedef multiset<PolicyEnforcement*, PointeeCompare<PolicyEnforcement*> > PolicyEnforcementContainer;
		typedef multiset<PolicyEnforcement*, PointeeCompare<PolicyEnforcement*> >::iterator PolicyEnforcementContainerIterator;

		static PolicyEnforcementEngine* getInstance();
		void add(PolicyEnforcement*);
		void remove(PolicyEnforcement*);
		void run();
		
	private:
		static PolicyEnforcementEngine* instance;
		boost::mutex mtx;
		PolicyEnforcementContainer policyEnforcements;
		PolicyEnforcement* popContainer();
		PolicyEnforcementEngine();
		Thread thread;
};

#endif

