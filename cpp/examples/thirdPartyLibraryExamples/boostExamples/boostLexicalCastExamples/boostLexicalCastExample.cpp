/**
 * Illustrates the use of boost::lexical_cast
 *
 * @file boostLexicalCastExample.cpp
 */


#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>

class streamable {
	public:
   		virtual void stream(std::ostream &) const = 0;
};

std::ostream &operator<<(std::ostream &out,streamable const &obj)
{
	obj.stream(out);
	return out;
}

// Now anything derived from streamable can be written to std::ostream
// For example:

class bar : public streamable {
	int x;
	int y;
public:
    bar(int a,int b) : x(a),y(b){}
    virtual void stream(std::ostream &out) const { out<<x<<":"<<y; }
};

int main()
{
    bar b(1,3);
    std::cout << b << std::endl;

    // and converted to string
    std::string str = boost::lexical_cast<std::string>(b);

    std::cout << str << std::endl;
}

