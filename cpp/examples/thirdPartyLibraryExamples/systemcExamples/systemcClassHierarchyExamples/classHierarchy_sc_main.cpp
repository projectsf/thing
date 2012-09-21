/**
 * Example includes one source and one sink connected
 * with a sc_fifo<T> channel
 *
 * Example demonstrates the following:
 * <ul>
 * <li> Calling sc_start() multiple times is
 * permitted and functions as expected.  This is
 * required for the UWB systemC model which
 * calls sc_start() on every new packet.
 * <li> Thread process can be registered by base
 * process and applies to all derived classes.
 * There was a concern that the process names
 * wouldn't be unique for the derived classes.
 * This is no longer a concern.
 * <li> Thread processes must be registered with
 * the kernel via the SC_THREAD call.  If this
 * call is omitted than the threads will not
 * execute.  There was a belief that using
 * primitive channels was enough to insure
 * a process being executed.  This is not true
 * <li> Thread processes can be halted with
 * systemC events that are triggered through
 * non systemC calls.  This functionality
 * is required by the UWB systemC model, which
 * has free running "source" blocks in the
 * Transmitter.  A local variable in ModuleBase
 * would indicate when the source block was
 * done transmitting.  When the thread
 * (wrapped in a while(true) ) would return
 * to the top it would see that the TX
 * is complete for that packet and wait
 * for a systemC event which was
 * triggered via a setter.
 * </ul>
 *
 * @file classHierarchy_sc_main.cpp
 * 
 */

#include "systemc.h"
#include "Source.h"
#include "Sink.h"

int sc_main(int argc, char *argv[])
{

  sc_fifo<bool> topSignal("topSignal",1);

  Source source("source");
  source.dataOut(topSignal);

  Sink sink("sink");
  sink.dataIn(topSignal);

  const unsigned int numIterations = 10;
  for(unsigned int ii=0; ii<numIterations; ++ii)
  {
    //std::cout << "Iteration = " << ii << std::endl;
    source.setStart(true);
    sc_start();
  }

  return 0;

}
