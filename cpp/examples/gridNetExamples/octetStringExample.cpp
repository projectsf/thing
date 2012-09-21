#include <map>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


struct OctetString
{
	char* value;
	unsigned int size;
}; 


class Foo
{
	public:
		Foo(struct OctetString str) 
		{
			octetString.value = new char[str.size + 1];
			strcpy(octetString.value, str.value);
			octetString.size = str.size;
		}

		~Foo()
		{
			delete[] octetString.value;
		}

		void setValue(const string& str)
		{
			delete[] octetString.value;
			octetString.value = new char[str.size()+1];
			//strcpy(octetString.value, const_cast<char*>(str.c_str()));
			strcpy(octetString.value, str.c_str());
			octetString.size = str.size();
		}

		string getValue() const
		{	
			return string(octetString.value, octetString.size);
		}

	private:
		struct OctetString octetString;
};


int main()
{
	struct OctetString os;
	os.value = "hello";
	os.size = strlen(os.value);
	Foo foo(os);

	//foo.setValue("hello");
	//foo.setValue("helloWorld");

	cout << "String: " << foo.getValue() << endl;


	string str("hello", 0);

	cout << "String: " << str << endl;

}
