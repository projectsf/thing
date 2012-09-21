#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Printer
{
	template<typename T>
	void operator() (T in)
	{
		std::cout << "Value: " << in << std::endl;
	}
};

int main()
{
	const unsigned int SIZE = 4;
	std::vector<double> tapVec(SIZE,.125);
	std::vector<double> dataVec(SIZE, 2);
	std::vector<double> results(SIZE);
	
	for_each(dataVec.begin(), dataVec.end(), Printer() );
	
	double sum = inner_product(tapVec.begin(), tapVec.end(), dataVec.begin(),0.0 );
	std::cout << "sum: " << sum << std::endl;
	for_each(dataVec.begin(), dataVec.end(), Printer() );
}
