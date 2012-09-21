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
	{
		ptree root;

		//populate scalar
		root.put("top", "top");

		//populate sequence
		vector<int> values;
		values.push_back(0);
		values.push_back(1);
		values.push_back(2);
		ptree nodes;
		for(vector<int>::const_iterator iter = values.begin(); iter != values.end(); ++iter)
		{
			ptree node;
			node.put("value", *iter);
			nodes.add_child("node", node);
		}
		root.add_child("nodes", nodes);

		//write out xml to stdout
		std::ostringstream oss;
		xml_parser::write_xml(oss, root);
		cout << oss.str() << endl;

		//write out xml to file
		xml_parser::write_xml(propertyTreeExampleFileName, root, std::locale(), boost::property_tree::xml_writer_make_settings(' ', 1));
	}

	{
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

		try
		{
			//extract scalar
			cout << "top: " << root.get<string>("top") << endl;
	
			//extract values from sequence with foreach
			ptree nodes = root.get_child("nodes"); 
			unsigned int index = 0;
			BOOST_FOREACH(boost::property_tree::ptree::value_type& node, nodes)
			{
				cout << "node[" << index << "].Value: " << node.second.get<string>("value") << endl;
			}

			//extract values from sequence, referencing root with foreach
			index = 0;
			BOOST_FOREACH(ptree::value_type& node, root.get_child("nodes"))
			{
				cout << "node[" << index << "].Value: " << node.second.get<string>("value") << endl;
			}

			//walk sequence with iterators
			index = 0;
			for(ptree::iterator iter = nodes.begin(); iter != nodes.end(); ++iter, ++index)
			{
				cout << "node[" << index << "].Value: " << iter->second.get<string>("value") << endl;
			}

			//walk sequence with iterators, ignoring key name
			index = 0;
			for(ptree::iterator iter = nodes.begin(); iter != nodes.end(); ++iter, ++index)
			{
				cout << "node[" << index << "].Value: " << iter->second.data() << endl;
			}

			//extract a sequence of non-nested "value"s from root, using equal_range
			//unsigned int index = 0;
			//std::pair<boost::property_tree::ptree::assoc_iterator, boost::property_tree::ptree::assoc_iterator> iters = root.equal_range("value");
			//for(boost::property_tree::ptree::assoc_iterator iter = iters.first; iter != iters.second; ++iter)
			//{
			//	cout << "node[" << index << "].Value: " << iter->second.data() << endl;
			//	++index;
			//}

		}

		catch(ptree_bad_path& exc)
		{
			cerr << "Parsing error: " << exc.what() << endl;
			exit(-1);
		}
	}
}



