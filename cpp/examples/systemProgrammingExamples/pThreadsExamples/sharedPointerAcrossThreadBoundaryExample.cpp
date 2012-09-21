/**
 * Example looks at passing shared pointers across
 * thread boundaries.
 * Object #1 creates and to Object #2, who clones it
 * Object #2
 *
 * @file pThreadsExample.cpp
 */
 
#include <pthread.h>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;


class Nugget
{
	public: 
		Nugget(const string& name) : name(name) 
		{
		}
		
		const string& getName() const
		{
			return name;
		}
	
		shared_ptr<Nugget> clone() const 
		{
			return shared_ptr<Nugget>(new Nugget(this->getName()));
		}
		
	private:
		string name;
}

void *RunFoo(void *otherFoo)
{

	Foo* foo = (Foo*)otherFoo;
	otherFoo->post(Nugget("Nugget"));
	printf("Hello World!\n");
	pthread_exit(NULL);

}

class Foo
{
	public:
		Foo(Foo* friend) : friend(friend)
		{
		}
		
		/* starts thread */
		void run()
		{
			rc = pthread_create(&thread, NULL, RunFoo, (void *)friend);	
		}
		
		void post(const Nugget& nugget)
		{
			shared_ptr<Nugget> localNugget = nugget.clone(); 
		}
	private:
		Foo* friend;
};



int main(int argc, char *argv[])
{
	Foo fooOne(NULL);
	Foo fooTwo(&fooOne);
	fooTwo.run(); 
}
