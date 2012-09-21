#include <iostream>
#include <fstream>
#include <map>

using namespace std;


int main()
{
	string versionInformationFileName ("./input/version-info");
	map<string, string> versions;
	string delimiter("=");

	//open file
	ifstream versionInformationFile(versionInformationFileName.c_str());
	while (!versionInformationFile.eof())
	{
		string version;
		getline(versionInformationFile, version);
		string::size_type index = version.find(delimiter);
		if (index != string::npos)
		{
			string key(version.substr(0, index));
			string value(version.substr(index + 1, version.size() - 1));
			pair<map<string, string>::iterator, bool> result = versions.insert(make_pair(key, value));
			if (!result.second)
			{
				cout << "Duplicate Key: " << key << ", with value: " << value << ", not inserting" << endl;
			}
		}
	}

	//walk map
	for (map<string, string>::const_iterator iter = versions.begin(); iter != versions.end(); ++iter)
	{
		cout << "key: " << iter->first << ", value: " << iter->second << endl;
	}
}
