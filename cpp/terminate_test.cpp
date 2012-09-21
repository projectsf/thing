
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

void (*orig_terminate_handler)();
void (*orig_unexpected_handler)();

void my_terminate_handler()
{
	cout << "in termination handler\n";
	orig_terminate_handler();
}

void my_unexpected_handler()
{
	cout << "in unexpected handler\n";
	orig_unexpected_handler();
}

class Scope
{
	static int depth;
	public:
		Scope() { cout << '<' << depth << '\n'; ++depth; }
		~Scope() { --depth; cout << '>' << depth << '\n'; }
};

int Scope::depth = 0;

void innerfunc()
{
	Scope s;
	throw runtime_error("hello");
}

void middlefunc()
{
	Scope s;
	innerfunc();
}

void middlefunc_abort()
{
	Scope s;
	abort();
}

void middlefunc_nothrow() throw ()
{
	Scope s;
	innerfunc();
}

int main(int argc,char *argv[])
{
	int test = 0;

	orig_terminate_handler = set_terminate(my_terminate_handler);
	orig_unexpected_handler = set_unexpected(my_unexpected_handler);

	if (argc == 2)
		test = atoi(argv[1]);

	cout << "test #" << test << '\n';

	Scope s;
	if (test == 0)
		try
		{
			middlefunc();
		}
		catch(runtime_error& e)
		{
			throw;
		}
	else if (test == 1)
		middlefunc_abort();
	else if (test == 2)
		middlefunc_nothrow();
}
