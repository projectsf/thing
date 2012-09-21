/**
 * Example overloads operator<< to support std::vector<T>
 *
 * @file ostreamForVector.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iterator>

using namespace std;

//write ints to file
template<typename T>
void writeToFile(const string& fileName, T value)
{
	ofstream outFile(fileName.c_str());
	outFile << value;
}
	
template<typename T>
void readFromFile(const string& fileName, T& value)
{
	ifstream inFile(fileName.c_str());
	inFile >> value;
}


int main() 
{
	string inFileName("./test-in.txt");
	string outFileName("./test-out.txt");

	//write int to file
	//int value = 3;
	//writeToFile(outFileName, value);

	//read int from file
	//value = 5;
	//readFromFile(outFileName, value);
	//cout << "Value: " << value << endl;

	//write string to file
	//string someString("someString");;
	//writeToFile(outFileName, someString);
	
	//read string from file
	//string someString;
	//readFromFile(outFileName, someString);
	//cout << "String: " << someString << endl;

	//copy a vector of strings to file delimited by spaces
	//vector<string> vv;
	//vv.push_back("hello");
	//vv.push_back("world");
	//ofstream outFile(outFileName.c_str());
	//ostream_iterator<string> ofile(outFile, "\n");
	//copy(vv.begin(), vv.end(), ofile);
	//outFile.close();

	//copy unsigned char to file
	vector<unsigned char> vv;
	vv.push_back(33);
	vv.push_back(34);
	ofstream outFile(outFileName.c_str());
	ostream_iterator<unsigned char> ofile(outFile, "\n");
	copy(vv.begin(), vv.end(), ofile);
	outFile.close();
 	

	//read back from file and print to cout with copy
	//vector<string> ww;
	//ifstream inFile("aFile.txt");
	//if (inFile)
	//{
//		copy(istream_iterator<string>(inFile), istream_iterator<string>(), back_inserter(ww));
//		copy(ww.begin(), ww.end(), ostream_iterator<string>(cout, "\n"));
//	}
//	else
//	{	
//		cerr << "No good" << endl;
//	}
}
