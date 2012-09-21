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
		
		virtual bool equal(const Element& rhs) const
		{
			cout << "base" << endl;
			return (key == rhs.getKey() && value == rhs.getValue());
		}

		bool notEqual(const Element& rhs) const
		{
			cout << "base" << endl;
			return !(this->equal(rhs))
		}
	
	protected:
		std::string key;
		int value;
		
};

class ConcreteElement : public Element
{
	public :
		ConcreteElement(const string& key, unsigned int valueOne, unsigned int valueTwo) : Element(key, valueOne), valueTwo(valueTwo)
		{
		}

		unsigned int getValueTwo() const
		{
			return valueTwo;
		}
		
		virtual bool equal(const Element& rhs) const
		{
			cout << "concrete" << endl;

			try
			{
				const ConcreteElement& concreteElement = dynamic_cast<const ConcreteElement&>(rhs); 
				return (key == concreteElement.getKey() && value == concreteElement.getValue() && valueTwo == concreteElement.getValueTwo());
			}
			catch (std::exception& exc)
			{
				cout << "caught exception" << endl;
			}
		}


	private:
		int valueTwo;

};

void generateReferenceSequence(vector<shared_ptr<Element> >& sequence, unsigned int numberElements)
{
	sequence.clear();

	for (unsigned int ii = 0; ii < numberElements; ++ii)
	{
		string key("e" + lexical_cast<string>(ii));
		sequence.push_back(shared_ptr<Element>(new ConcreteElement(key, ii, ii)));
	}
}

void generateUpdatedSequence(vector<shared_ptr<Element> >& sequence, unsigned int numberElements)
{
	sequence.clear();

	for (unsigned int ii = 0; ii < numberElements; ++ii)
	{
		//string key("e" + lexical_cast<string>(numberElements - ii));
		string key("e" + lexical_cast<string>(ii));
		sequence.push_back(shared_ptr<Element>(new ConcreteElement(key, ii, ii)));
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

void createDeltaSequence(const vector<shared_ptr<Element> >& referenceSequence, const vector<shared_ptr<Element> >& updateSequence, vector<shared_ptr<Element> >& deltaSequence)
{
	//linear search for delta element (lame)
	for (vector<shared_ptr<Element> >::const_iterator updateIter = updateSequence.begin(); updateIter != updateSequence.end(); ++updateIter)
	{
		bool found = false;
		for (vector<shared_ptr<Element> >::const_iterator referenceIter = referenceSequence.begin(); referenceIter != referenceSequence.end(); ++referenceIter)
		{
			if ((*referenceIter)->getKey() == (*updateIter)->getKey())
			{
				found = true;

				//assume same type and attempt to cast
				

				if ( (*referenceIter)->notEqual(*(*updateIter)))
				{
					deltaSequence.push_back(*updateIter);
				}

				break;
			}
		}

		//corner case.  if not found, add to reference container
		if (!found)
		{
			deltaSequence.push_back(*updateIter);
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

	//create delta sequence
	vector<shared_ptr<Element> > deltaSequence;
	createDeltaSequence(referenceSequence, updatedSequence, deltaSequence);
	cout << "Delta Sequence: " << endl;
	print(deltaSequence);
	cout << "-------" << endl;

	//update reference sequence
	updateReferenceSequence(referenceSequence, deltaSequence);
	cout << "Updated Reference: " << endl;
	print(referenceSequence);
	cout << "-------" << endl;

}
