/**
 * Code was used to investigate sc_export
 *
 * Lessons learned :
 * <ul>
 * <li> Performance when using sc_export is significantly
 * improved. <br>
 * sc_export eliminates allows both read and write threads
 * that access a systemC channel to exist as one thread,
 * which cuts down on context switching.
 * <li> A sc_export must be bound to a systemC channel
 * in the sc_module that declares an sc_export.
 * <li> sc_export channels are bound by referncing
 * the sc_export port explicitly
 * </ul>
 *
 * @file scExport_sc_main.cpp
 */
 
#include "systemc.h"
#include "Source.h"
#include "Sink.h"

int sc_main(int argc, char *argv[])
{

  //sc_fifo<bool> topSignal("topSignal", 1000);

  Source source( "testMod" );

  //sc_export<sc_fifo<bool> > > tempPort((*(source.dataOutIntf[0])));
  //sc_export<sc_fifo<bool> > > tempPort((*(source.dataOutIntf[0])));

  //Sink sink( "sink" ); 
  //sink.dataIn( (*(source.dataOutIntf[0])) );


  const unsigned int numIterations = 100000;
  for(unsigned int ii=0; ii<numIterations; ++ii)
  {
    //std::cout << "Iteration = " << ii << std::endl;
    source.setStart(true);
    std::cout << "Reading an element" << std::endl;
    std::cout << source.dataOut.read();
    sc_start();
  }

  return 0;

}
