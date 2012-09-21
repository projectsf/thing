#include "systemc"
#include <iostream>

using namespace sc_core;

struct Producer : public sc_module
{
	sc_fifo_out<int> fifoOut;
	SC_CTOR(Producer)
	{
		SC_THREAD(execute);
	}
	void execute()
	{
	  for(unsigned int ii =0; ii < 10; ++ii) {
		  fifoOut.write(ii);
	  }
	}
};

struct Consumer : public sc_module
{
	sc_fifo_in<int> fifoIn;
	SC_CTOR(Consumer)
	{
		SC_THREAD(execute);
	}
	void execute()
	{
		for(unsigned int ii =0; ii < 10; ++ii) {
		  std::cout << "Read: " << fifoIn.read() << std::endl;
	  }
	}
};
		

int sc_main(int ac, char* av[])
{
	sc_fifo<int> channel("fifoChannel");

  Producer producer("producer");
  Consumer consumer("consumer");
  
  producer.fifoOut(channel);
  consumer.fifoIn(channel);
  
  sc_start();
	
	return 1; 
	
}
