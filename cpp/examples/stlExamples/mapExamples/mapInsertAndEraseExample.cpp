#include <string>
#include <iostream>
#include <map>


using namespace std;

int main()
{
	typedef map<unsigned int, unsigned int> ContainerType;
	ContainerType values;
	values.insert(make_pair<unsigned int, unsigned int>(9, 0));
	values.insert(make_pair<unsigned int, unsigned int>(2, 0));
	values.insert(make_pair<unsigned int, unsigned int>(3, 0));
	values.insert(make_pair<unsigned int, unsigned int>(7, 0));
	values.insert(make_pair<unsigned int, unsigned int>(1, 200));

	//attempt to insert in container
	std::pair<ContainerType::iterator, bool> result = values.insert(make_pair<unsigned int, unsigned int>(10, 200));
				
	if (result.second)
	{
		//new element successfully inserted
		cout << "inserted" << endl;
	}
				
	else
	{
		cout << "already there, updating" << endl;
		//active precedence, update value
		result.first->second = 9 ;
	}

	//attempt to insert in container
	result = values.insert(make_pair<unsigned int, unsigned int>(1, 200));
				
	if (result.second)
	{
		//new element successfully inserted
		cout << "inserted" << endl;
	}
				
	else
	{
		//active precedence, update value
		cout << "already there, updating" << endl;
		result.first->second = 309;
	}

	//erase element
	unsigned int newValue = 34;
	bool elementErased = values.erase(newValue);

	if (elementErased)
	{
		cout << "Erased key: " << newValue << endl;
	}
	else
	{
		cout << "Nothing erased" << endl;
	}


	newValue  = 1;
	elementErased = values.erase(newValue);

	if (elementErased)
	{
		cout << "Erased key: " << newValue << endl;
	}
	else
	{
		cout << "Nothing erased" << endl;
	}


	for (ContainerType::const_iterator iter = values.begin(); iter != values.end(); ++iter)
	{
		cout << "Value: " << iter->first << endl;
	}

    //what is max?
	ContainerType::const_reverse_iterator iter = values.rbegin();
	cout << "Max Key: " << iter->first << endl;

	
	//is new value max

}
