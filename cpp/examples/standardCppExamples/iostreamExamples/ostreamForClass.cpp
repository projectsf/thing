#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>


using namespace std;
using namespace boost;



class Foo
{
	//friend ostream& operator<<(ostream&, const Foo&);

	public:
		Foo(const string& name) : name(name)
		{
		}

		virtual string getName() const
		{
			return name;
		}
	
		virtual ~Foo(){};


	protected:
		string name;
};

ostream& operator<<(ostream& os, const Foo& foo)
{
	os << foo.getName() << endl;
	return os;
}

class Bar : public Foo
{
	public:
		Bar(const string& name) : Foo(name)
		{
		}

		string getName() const
		{
			return string("Foo:" + name);
		}

		virtual ~Bar(){}
};

int main()
{
	Foo foo("fooOne");
	Foo fooTwo("fooTwo");
	shared_ptr<Foo> fooThree(new Foo("fooThree"));
	shared_ptr<Bar> barOne(new Bar("barOne"));

	cout << foo << fooTwo << *fooThree << *barOne << endl;
}
