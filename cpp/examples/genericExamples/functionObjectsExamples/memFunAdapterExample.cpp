#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <boost/function.hpp>


using namespace std;

class Runnable
{
	public:
		void run()
		{ 
			cout << "Running" << endl; 
		}
	
};

template<typename Fn, typename Arg>
class GenericRunnable : public Runnable
{
	public:
		GenericRunnable(Fn fn, Arg* arg) : fn(fn), arg(arg)
		{
		}
		
		void run()
		{
			fn(arg);
		}
		
	private:
		Fn fn;
		Arg* arg;
};


class Foo
{
	public:
		Foo() : runnable(std::mem_fun(&Foo::doSomething), this)
		{
		}
		
		void doSomething()
		{
			cout << "Foo's doing something" << endl;
		}
		
		void operator()()
		{
			runnable.run();
		}
	private:
		GenericRunnable<std::mem_fun_t<void, Foo>, Foo> runnable;
};



int main()
{
	Foo foo;
	foo();
}


	
