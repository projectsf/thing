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
 * @file trace_sc_main.cpp
 */


#include <systemc.h>
#include "Producer.hpp"
#include "Consumer.hpp"
 
int sc_main(int argc, char *argv[])
{
  typedef unsigned int T;
  typedef sc_fifo<T> ChannelType;
  typedef sc_fifo_in<T> InputType;
  typedef sc_fifo_out<T> OutputType;
  
  ChannelType value("value");
  const unsigned int PRODUCER_DELAY = 100;
  const unsigned int CONSUMER_DELAY = 30;

  sc_set_time_resolution(1, SC_NS);

  Producer<OutputType> producer("Producer", PRODUCER_DELAY);
  producer.out(value);
 
  Consumer<InputType> consumer("Consumer", CONSUMER_DELAY);
  consumer.in(value);
  
  sc_trace_file* tf = sc_create_vcd_trace_file("trace");
  sc_trace(tf, producer.out, "producer.out");
  sc_trace(tf, consumer.in, "consumer.in");

  sc_start();

  sc_close_vcd_trace_file(tf);

  return 1;
 
}
