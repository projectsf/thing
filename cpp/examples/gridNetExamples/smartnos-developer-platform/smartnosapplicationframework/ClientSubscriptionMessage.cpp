#include "ClientSubscriptionMessage.hpp"
#include <boost/property_tree/xml_parser.hpp>
#include <sstream>
#include "./include/SmartNosApplication.hpp"

using namespace std;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;

ClientSubscriptionMessage::ClientSubscriptionMessage(const std::string& message)
{
    //convert string to stringstream
    istringstream iss(message);
   
    //read in to property tree
    read_xml(iss, this->message, trim_whitespace);
}

ClientSubscriptionMessage::ClientSubscriptionMessage(const SmartNosApplication* application)
{
	message.put("ApplicationIdentifier", application->getApplicationIdentifier());
	message.put("Action", "Subscribe");
}

void ClientSubscriptionMessage::unmarshall(const string& message)
{
}

void ClientSubscriptionMessage::marshall(string& message)
{
}

string ClientSubscriptionMessage::getApplicationIdentifier() const
{
	try
	{
		return message.get<string>("ApplicationIdentifier");
	}
	catch(ptree_bad_path& exc)
	{
		cout << "Parsing error: " << exc.what() << endl;
		return string();
	}
}

string ClientSubscriptionMessage::getClassIdentifier() const
{
	try
	{
		return message.get<string>("ClassIdentifier");
	}
	catch(ptree_bad_path& exc)
	{
		//cout << "Parsing error: " << exc.what() << endl;
		return string();
	}
}


ClientSubscriptionMessage::Action ClientSubscriptionMessage::getAction() const
{
	try
	{
		string actionAttribute = message.get<string>("Action");
		if ("Subscribe" == actionAttribute)
		{
			return Subscribe;
		}
		else if ("Unsubscribe" == actionAttribute)
		{
			return Unsubscribe;
		}
		else
		{
			return Unknown;
		}
	}
	catch(ptree_bad_path& exc)
	{
		cout << "Parsing error: " << exc.what() << endl;
		return Unknown;
	}
}

string ClientSubscriptionMessage::getMessage() const
{
	//write out xml to stdout
	ostringstream oss;
	xml_parser::write_xml(oss, message);
	return oss.str();
}
