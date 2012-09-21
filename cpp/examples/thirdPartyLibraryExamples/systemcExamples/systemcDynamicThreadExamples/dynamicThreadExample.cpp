
#include "DynamicThread.hpp"
#include <systemc>
#include <iostream>



int sc_main(int argc, char *argv[]){ 
 
  DynamicThread("DynamicThread");
  sc_start();

  return 1;
 
}
