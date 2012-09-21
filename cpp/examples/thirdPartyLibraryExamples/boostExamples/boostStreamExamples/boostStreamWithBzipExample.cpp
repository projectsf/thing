/**
 * Illustrates the use of boost streams
 *
 * @file boostStreamExample.cpp
 */

#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <sstream>

using namespace std;
using namespace boost::iostreams;
using namespace boost::iostreams::bzip2;

int main() 
{
	string uncompressedInFileName("./hello.txt");
	string compressedOutFileName("./hello.txt.bz2");
	string uncompressedOutFileName("./hello.txt.uncompressed");

	//compress and write out to file
	{

		cout << "Compressing : " << uncompressedInFileName << " and writing out to: " << compressedOutFileName << endl;
		//compress contents of input file
    	ifstream ifile(uncompressedInFileName.c_str(), ios_base::in);
    	filtering_streambuf<input> in;
		in.push(boost::iostreams::bzip2_compressor());  // your compressor here
		in.push(ifile);

		//write compressed file out to fs
		std::ofstream ofile(compressedOutFileName.c_str(), std::ios::binary);
    	boost::iostreams::copy(in, ofile);
	}

	//decompress and write out to file
	{

		cout << "Uncompressing : " << compressedOutFileName << " and writing out to: " << uncompressedOutFileName << endl;
		//read in and uncompress compressed file
    	ifstream ifile(compressedOutFileName.c_str(), ios_base::in | ios_base::binary);
		filtering_streambuf<input> in;
		in.push(bzip2_decompressor());
		in.push(ifile);

		//write compressed file out to fs
		std::ofstream ofile(uncompressedOutFileName.c_str());
    	boost::iostreams::copy(in, ofile);
	}

	//compress and write out to a byte buffer
	{

		cout << "Reading : " << uncompressedInFileName << " into stringstream" << endl;
		//compress contents of input file
    	ifstream ifile(uncompressedInFileName.c_str(), ios_base::in);

		//compress stringstream
		stringstream ss;
		ss << ifile;
    	filtering_streambuf<input> in;
		in.push(boost::iostreams::bzip2_compressor());  // your compressor here
		in.push(ss);

		stringstream oss1;
   		boost::iostreams::copy(in, oss1);

		//decompress and write out to stdout
		cout << "Uncompressing stringstream and writing out to: stdout" << endl;

		filtering_streambuf<input> in2;
		in2.push(bzip2_decompressor());
		in2.push(oss1);

		//write compressed file out to fs
		ostringstream oss2;
   		boost::iostreams::copy(in2, oss2);
		cout << oss2.str() << endl;

	}
}
