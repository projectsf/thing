/**
 * Illustrates the use of boost property tree
 *
 *
 * @file boostPropertyTree.cpp
 */

#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace std;

int main()
{
	string attributes("-1.0,3.2,-3.5");

	char_separator<char> sep(",");
	tokenizer< char_separator<char> > tokens(attributes, sep);

	vector<string> values;
	for (tokenizer< char_separator<char> >::iterator iter = tokens.begin(); iter != tokens.end(); ++iter)
	{
		values.push_back(*iter);
	}

	for (vector<string>::iterator iter = values.begin(); iter != values.end(); ++iter)
	{
		if (iter == values.begin())
		{
			cout << "Value: " << *iter;
		}
		else
		{
			cout << ", Value: " << *iter;
		}
	}

	cout << endl;
}



