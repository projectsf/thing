#include "./include/ApplicationMessage.hpp"
#include <boost/property_tree/xml_parser.hpp>
#include <sstream>
#include "./include/SmartNosApplication.hpp"

using namespace std;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;

ApplicationMessage::ApplicationMessage(const string& message)
{
	//convert string to stringstream
	istringstream iss(message);

	//read in to property tree
	read_xml(iss, this->message, trim_whitespace);
}

ApplicationMessage::MessageType ApplicationMessage::getMessageType() const
{
	try
	{
		string messageType = message.get<string>("MessageType");
		if ("ApplicationLifecycle" == messageType)
		{
			return ApplicationLifecycle;
		}
		else if ("ApplicationMessagePayload" == messageType)
		{
			return ApplicationMessagePayload;
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

string ApplicationMessage::getMessage() const
{
	//write out xml to stdout
	ostringstream oss;
	xml_parser::write_xml(oss, message);
	return oss.str();
}

string ApplicationMessage::getApplicationIdentifier() const
{
	return "Unknown";
}


ApplicationPayloadMessage::ApplicationPayloadMessage(const string& message) :
ApplicationMessage(message)
{
}

string ApplicationPayloadMessage::getApplicationIdentifier() const
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


ApplicationLifecycleMessage::ApplicationLifecycleMessage(const string& message) :
ApplicationMessage(message)
{
}

string ApplicationLifecycleMessage::getApplicationIdentifier() const
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

ApplicationLifecycleMessage::Action ApplicationLifecycleMessage::getAction() const
{
	try
	{
		string action = message.get<string>("LifecycleAction");
		if ("Start" == action)
		{
			return Start;
		}
		else if ("Stop" == action)
		{
			return Stop;
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
