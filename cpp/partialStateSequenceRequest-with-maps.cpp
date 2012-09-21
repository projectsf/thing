#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class Element
{
	public:
		Element(const string& key, unsigned int value) : key(key), value(value) 
		{
		}

		~Element()
		{
		}

		const string& getKey() const 
		{
			return key;
		}

		unsigned int getValue() const
		{
			return value;
		}
	
	private:
		std::string key;
		int value;
		
};

void generateReferenceSequence(vector<shared_ptr<Element> >& sequence, unsigned int numberElements)
{
	sequence.clear();

	for (unsigned int ii = 0; ii < numberElements; ++ii)
	{
		string key("e" + lexical_cast<string>(ii));
		sequence.push_back(shared_ptr<Element>(new Element(key, ii)));
	}
}

void generateUpdatedSequence(vector<shared_ptr<Element> >& sequence, unsigned int numberElements)
{
	sequence.clear();

	for (unsigned int ii = 0; ii < numberElements; ++ii)
	{
		string key("e" + lexical_cast<string>(numberElements - ii));
		sequence.push_back(shared_ptr<Element>(new Element(key, ii)));
	}
}

void print(const vector<shared_ptr<Element> >& sequence)
{
	for (vector<shared_ptr<Element> >::const_iterator iter = sequence.begin(); iter != sequence.end(); ++iter)
	{
		cout << "Key: " << (*iter)->getKey() << ", Value: " << (*iter)->getValue() << endl;
	}
}

void print(const map<string, shared_ptr<Element> >& sequence)
{
	for (map<string, shared_ptr<Element> >::const_iterator iter = sequence.begin(); iter != sequence.end(); ++iter)
	{
		cout << "Key: " << iter->second->getKey() << ", Value: " << iter->second->getValue() << endl;
	}
}

void moveToAssociativeContainer(const vector<shared_ptr<Element> >& sequence, map<string, shared_ptr<Element> >& associativeSequence)
{
	for (vector<shared_ptr<Element> >::const_iterator iter = sequence.begin(); iter != sequence.end(); ++iter)
	{
		associativeSequence.insert(make_pair((*iter)->getKey(), *iter));
	} 
}

void createDeltaSequence(const map<string, shared_ptr<Element> >& referenceSequence, const map<string, shared_ptr<Element> >& updatedSequence, vector<shared_ptr<Element> >& deltaSequence)
{
	//look for elements in second list that are in first list but that have changed.
    //if present add to delta list
	for (map<string, shared_ptr<Element> >::const_iterator iter = updatedSequence.begin(); iter != updatedSequence.end(); ++iter)
	{
		//look for matching key in reference container
		map<string, shared_ptr<Element> >::const_iterator findIter = referenceSequence.find(iter->first);
		if (findIter != referenceSequence.end())
		{
			//compare values, if different than add
			if (iter->second->getValue() != findIter->second->getValue())
			{	
				deltaSequence.push_back(iter->second);
			}
		}
		else
		{
			deltaSequence.push_back(iter->second);
		}
	}
}

void updateReferenceSequence(vector<shared_ptr<Element> >& referenceSequence, const vector<shared_ptr<Element> >& deltaSequence)
{
	//linear search for delta element (lame)
	for (vector<shared_ptr<Element> >::const_iterator deltaIter = deltaSequence.begin(); deltaIter != deltaSequence.end(); ++deltaIter)
	{

		bool found = false;
		for (vector<shared_ptr<Element> >::iterator referenceIter = referenceSequence.begin(); referenceIter != referenceSequence.end(); ++referenceIter)
		{
			if ((*referenceIter)->getKey() == (*deltaIter)->getKey())
			{
				found = true;
				*referenceIter = *deltaIter;
			}
		}

		//corner case.  if not found, add to reference container
		if (!found)
		{
			referenceSequence.push_back(*deltaIter);
		}
	}	
}

int main()
{
	const unsigned int NumberReferenceElements = 5;
	const unsigned int NumberUpdatedElements = 3;

	//generate reference superset vector
	vector<shared_ptr<Element> > referenceSequence;
	generateReferenceSequence(referenceSequence, NumberReferenceElements);
	cout << "-------" << endl;
	cout << "Reference Sequence: " << endl;
	print(referenceSequence);
	cout << "-------" << endl;
	
	//generate update sequence
	vector<shared_ptr<Element> > updatedSequence;
	generateUpdatedSequence(updatedSequence, NumberUpdatedElements);
	cout << "Updated Sequence: " << endl;
	print(updatedSequence);
	cout << "-------" << endl;

	//migrate both to maps
	map<string, shared_ptr<Element> > referenceMap;
	map<string, shared_ptr<Element> > updatedMap;
	moveToAssociativeContainer(referenceSequence, referenceMap);
	moveToAssociativeContainer(updatedSequence, updatedMap);

	//create delta sequence
	vector<shared_ptr<Element> > deltaSequence;
	createDeltaSequence(referenceMap, updatedMap, deltaSequence);
	cout << "Delta Sequence: " << endl;
	print(deltaSequence);
	cout << "-------" << endl;

	//update reference sequence
	updateReferenceSequence(referenceSequence, deltaSequence);
	cout << "Updated Reference: " << endl;
	print(referenceSequence);
	cout << "-------" << endl;

}
