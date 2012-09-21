/**
 * Example illustrates use of simulator time in SystemC
 *
 * Example illustrates:
 * <ul>
 * <li> If using blocking sc_fifo channels, a consumer will not start reading data
 * until time that was specified in the wait(time, SC_NS) call has expired.
 * <li> If using sc_signal "non-blocking" this does not work.
 * </ul>
 *
 * @file timeModeling_sc_main.cpp
 */


#include <systemc.h>
#include "Producer.hpp"
#include "Consumer.hpp"
 
int sc_main(int argc, char *argv[])
{
  typedef bool T;
  typedef sc_fifo<T> ChannelType;
  typedef sc_fifo_in<T> InputType;
  typedef sc_fifo_out<T> OutputType;
  
  ChannelType done("done");
  const unsigned int PRODUCER_DELAY = 100;
  const unsigned int CONSUMER_DELAY = 30;
 
  Producer<OutputType> producer("Producer", PRODUCER_DELAY);
  producer.done(done);
 
  Consumer<InputType> consumer("Consumer", CONSUMER_DELAY);
  consumer.done(done);
 
  sc_start();

  return 1;
 
}
