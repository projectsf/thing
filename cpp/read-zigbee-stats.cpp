#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


int main()
{
	const string::size_type PaddedLength = 60;
	vector<string> zigbeeStatus;
	//container = sequence of strings all fixed length (left justified, and space padded)
	//esi-eui, status = online/offline, pan id, extended-pan-id, channel, network key, network short address, link keys (length = 12), devices (length = 12)

	//vector of one line files
	vector<string> oneValueFiles;
	oneValueFiles.push_back("./input/eui");
	oneValueFiles.push_back("./input/network");
	oneValueFiles.push_back("./input/pan-id");
	oneValueFiles.push_back("./input/extended-pan-id");
	oneValueFiles.push_back("./input/channel");
	oneValueFiles.push_back("./input/nwk-key");
 
	//vector of one line files
	vector<string> valueSequenceFiles;
	valueSequenceFiles.push_back("./input/devices");
	valueSequenceFiles.push_back("./input/link-keys");

	for (vector<string>::const_iterator iter = oneValueFiles.begin(); iter != oneValueFiles.end(); ++iter)
	{
		ifstream attributeFile(iter->c_str());
		if (attributeFile.is_open())
		{
			string value;
			getline(attributeFile, value);
			value.insert(value.begin(), PaddedLength - value.size(), ' ');
			zigbeeStatus.push_back(value);
		}
		else
		{
			cout << *iter << " : No such file or directory " << endl;
		}
	}

	for (vector<string>::const_iterator iter = valueSequenceFiles.begin(); iter != valueSequenceFiles.end(); ++iter)
	{
		ifstream attributeFile(iter->c_str());
		if (attributeFile.is_open())
		{
			while (!attributeFile.eof())
			{
				string value;
				getline(attributeFile, value);
				value.insert(value.begin(), PaddedLength - value.size(), ' ');
				zigbeeStatus.push_back(value);
			}
		}
		else
		{
			cout << *iter << " : No such file or directory " << endl;
		}
	}

	cout << "Result: " << endl;
	for (vector<string>::const_iterator iter = zigbeeStatus.begin(); iter != zigbeeStatus.end(); ++iter)
	{
		cout << "[" << *iter << "]" << endl;
	}
}
