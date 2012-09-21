/**
 * Illustrates the use of boost::lexical_cast
 *
 * @file boostLexicalCastExample.cpp
 */


#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>

using namespace std;
using namespace boost;

int main()
{
    string completeOid("1.3.6.1.2.2.1");
	string::size_type index = completeOid.find_last_of('.');
	string objectIdentifier(completeOid, 0, index-2);
	unsigned int instanceIdentifier = lexical_cast<unsigned int>(string(completeOid, index+1, completeOid.size()));

	cout << "CompleteOid: " << completeOid << ", ObjectIdentifier: " << objectIdentifier << ", InstanceIdentifier: " << instanceIdentifier << endl;

	//trim
	while ((index = completeOid.find('.')) != string::npos)
	{
		completeOid.erase(index, 1);
	}

	cout << "completeOid stripped: " << completeOid << endl;

}

