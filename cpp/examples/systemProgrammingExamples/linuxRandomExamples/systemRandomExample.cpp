#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int devUrandomFd;

int random(int scale)
{
	int len = 0, randomValue;

	// Read entropy from 'devUrandomFd' into 'randomValue'
	while (1)
	{
		int numRead = read(devUrandomFd, ((char*)&randomValue) + len, sizeof(randomValue) - len);
		if (numRead == 0 || numRead == -1)
		{
			break;
		}
		len += numRead;
		if (len == sizeof(randomValue))
		{
			break;
		}
	}

	// Mask bits not included in 'RAND_MAX'
	randomValue &= RAND_MAX;

	if (scale)
	{
		return randomValue % scale;
	}
	
	return randomValue;

}

int main()
{
	devUrandomFd = open("/dev/urandom", O_RDONLY);
	if (devUrandomFd < 0)
	{
		cerr << "Unable to open \'/dev/urandom\' - Entropy sub-system uninitialized." << endl;
	}

	set<int> randomValues;
	const unsigned int numberIterations = 30000;

	for (unsigned int ii = 0; ii < numberIterations; ++ii)
	{
		int value = random(1200);
		cout << value << endl;
		std::pair<set<int>::iterator, bool> result = randomValues.insert(value);
		if (!result.second)
		{
			cout << "Duplicate found!" << endl;
			break;
		}
	}

	close(devUrandomFd);
}
