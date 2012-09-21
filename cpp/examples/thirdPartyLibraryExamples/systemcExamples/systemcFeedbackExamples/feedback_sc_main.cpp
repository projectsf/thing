/**
 * Example includes a model with feedback
 *
 * Example demonstrates the following:
 * <ul>
 * <li> That a SystemC architecture
 * based on sc_fifo channels with feedback
 * will lock up, if all fifo accesses
 * are blocking read() calls.
 * <li> If one input port is known to be connected
 * to a feedback path, than accessing the channel
 * through this port
 * can be done via a nb_read() call for the
 * first access and then read() calls for the
 * subsequent accesses
 * <li> It is also possible to access this channel
 * through the port with all nb_read() calls.
 * <li> A sc_fifo doesn't have to be full
 * for it to be read.  This example sets up
 * the channels to be sized = BLOCKSIZE
 * but the feedback structure with one nb_read()
 * writes and reads one sample at a time.
 * </ul>
 *
 * @file feedback_sc_main.cpp
 * 
 */

#include "systemc.h"
#include "Source.h"
#include "Sink.h"
#include "DeMux.h"
#include "Mux.h"

int sc_main(int argc, char *argv[])
{

  const unsigned int BLOCKSIZE = 16;

  sc_fifo<bool> sourceOut("sourceOut",BLOCKSIZE);
  sc_fifo<bool> muxOut("muxOut",BLOCKSIZE);
  sc_fifo<bool> deMuxFeedThru("deMuxFeedThru",BLOCKSIZE);
  sc_fifo<bool> deMuxFeedBack("deMuxFeedBack",BLOCKSIZE);

  Source source("source", BLOCKSIZE, true);
  source.dataOut(sourceOut);

  Mux mux("mux", BLOCKSIZE);
  mux.dataInOne(sourceOut);
  mux.dataInTwo(deMuxFeedBack);
  mux.dataOut(muxOut);

  DeMux deMux("deMux");
  deMux.dataIn(muxOut);
  deMux.dataOutOne(deMuxFeedThru);
  deMux.dataOutTwo(deMuxFeedBack);

  Sink sink("sink", true);
  sink.dataIn(deMuxFeedThru);

  sc_start();

  return 0;

}
