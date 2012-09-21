/**
 * Illustrates the use of boost property tree
 *
 *
 * @file boostPropertyTree.cpp
 */

#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::property_tree;
using namespace std;

int main()
{
	string propertyTreeExampleFileName("property-tree-example.xml");
	ptree root;
	try
	{
		xml_parser::read_xml(propertyTreeExampleFileName, root);
	}
	catch(xml_parser::xml_parser_error& exc)
	{
		cerr << "Parsing error: " << exc.what() << endl;
		exit(-1);
	}

	vector<string> phaseRemoveKeys;
	//phaseRemoveKeys.push_back("Voltage");
	//phaseRemoveKeys.push_back("Current");
	phaseRemoveKeys.push_back("PowerFactor");
	bool removeFrequency = false;

	try
	{
		boost::property_tree::ptree::assoc_iterator powerQualityProfileIter = root.find("PowerQualityProfile");
		//extract a sequence of non-nested "value"s from root, using equal_range
		unsigned int index = 0;
		std::pair<boost::property_tree::ptree::assoc_iterator, boost::property_tree::ptree::assoc_iterator> entryIters = powerQualityProfileIter->second.equal_range("Entry");
		for(boost::property_tree::ptree::assoc_iterator entryIter = entryIters.first; entryIter != entryIters.second; ++entryIter)
		{
			if (removeFrequency)
			{
				try
				{
					entryIter->second.erase("Frequency");
					cout << "deleting: Frequency" << endl;
				}
				catch(ptree_bad_path& exc)
				{
					cout << "some error" << endl;
				}
			}

			std::pair<boost::property_tree::ptree::assoc_iterator, boost::property_tree::ptree::assoc_iterator> elementIters = entryIter->second.equal_range("Element");
			for(boost::property_tree::ptree::assoc_iterator elementIter = elementIters.first; elementIter != elementIters.second; ++elementIter)
			{
				std::pair<boost::property_tree::ptree::assoc_iterator, boost::property_tree::ptree::assoc_iterator> phaseIters = elementIter->second.equal_range("Phase");
				for(boost::property_tree::ptree::assoc_iterator phaseIter = phaseIters.first; phaseIter != phaseIters.second; ++phaseIter)
				{
					for (vector<string>::const_iterator iter = phaseRemoveKeys.begin(); iter != phaseRemoveKeys.end(); ++iter)
					{
						try
						{
							phaseIter->second.erase(*iter);
							cout << "deleting: " << *iter << endl;
						}
						catch(ptree_bad_path& exc)
						{
							cout << "some error" << endl;
						}
					}
					
				}
			}
		}

		string propertyTreeExampleOutputFileName("property-tree-example-stripped.xml");
	
		//write out xml to file
		xml_parser::write_xml(propertyTreeExampleOutputFileName, root, std::locale(), boost::property_tree::xml_writer_make_settings(' ', 1));
	}

	catch(ptree_bad_path& exc)
	{
		cerr << "Parsing error: " << exc.what() << endl;
		exit(-1);
	}

}



