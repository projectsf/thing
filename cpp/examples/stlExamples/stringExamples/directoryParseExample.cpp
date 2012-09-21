#include <iostream>
#include <string>

using namespace std;

int main()
{
	string directory("/home/conf/active/wimax/auth-material");
	string createDirectory;

	string::size_type index = string::npos;
	while((index = directory.find_first_of("/")) != string::npos)
	{
		createDirectory = createDirectory + directory.substr(0, index+1);
		cout << "creating: " << createDirectory << endl;
		directory = directory.substr(index+1, directory.size()-index);
	}

	//one last time
	createDirectory = createDirectory + directory;
	cout << "creating: " << createDirectory << endl;
}

