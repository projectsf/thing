/**
 * Example looks at using posix semaphores 
 *
 * @file semaphoreExample.cpp
 */
 
#include <semaphore.h>
#include <iostream>


using namespace std;

static sem_t semaphore;

void foo()
{
	cout << "Foo() Acquiring lock" << endl;
	sem_wait(&semaphore);
	cout << "Foo() Got Lock" << endl;
}

int main(int argc, char *argv[])
{
	sem_init(&semaphore, 0, 1);

	cout << "Main acquiring lock" << endl;
	sem_wait(&semaphore);
	cout << "Main got Lock" << endl;
	foo();
	sem_post(&semaphore);

}
