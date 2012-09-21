/**
 * Example illustrates how to forward types without slicing them
 */

#include <iostream>
#include <string>
using namespace std;



class Bar
{
	public:
		virtual string getName() const {return name;}
		Bar(string name = "Base") : name(name) {}
	protected:
		string name;
};

class Derived : public Bar
{
	public:
		Derived() : Bar("Derived"), value(3) {}
		int getValue() const {return value;}
	private:
		int value;
};



void foo(const Bar& bar)
{
	cout << "foo(): Scope = " << bar.getName() << endl;
	cout << "foo(): Address of Bar = " << &bar << endl;
	if (bar.getName() == "Derived") {
		const Derived& derived = const_cast<Derived&>(dynamic_cast<Derived&>((bar));
		cout << "Value: " << derived.getValue() << endl;
	}
}



int main()
{

	Bar bar;
	cout << "main(): Scope = " << bar.getName() << endl;
	cout << "main(): Address of Bar = " << &bar << endl;
	Derived derived;
	cout << "main(): Scope = " << derived.getName() << endl;
	cout << "main(): Address of Bar = " << &derived << endl;
	
	foo(bar);
	foo(derived);
	
}

