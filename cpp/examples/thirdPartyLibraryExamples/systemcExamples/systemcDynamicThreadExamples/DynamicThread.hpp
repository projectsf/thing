#include <systemc.h>
#include <iostream>

SC_MODULE(DynamicThread) {
  SC_CTOR(DynamicThread) {
    SC_THREAD(mainThread);
  }
  void mainThread();
  void dynamicThread(double);
};


void DynamicThread::mainThread()
{
  std::cout << "Starting " << name() << std::endl;
  wait(1,SC_NS);
  sc_process_handle h1 = sc_spawn((sc_bind(&DynamicThread::dynamicThread, this, 15.0),"d1"));
  wait(3,SC_NS);
  sc_process_handle h2 = sc_spawn((sc_bind(&DynamicThread::dynamicThread, this, 15.0),"d2"));
  h1.wait();
  std::cout << "h1 finished" << std::endl;
}

void DynamicThread::dynamicThread(double d)
{
  const char* me = sc_get_curr_process_handle()->name();
  sc_time now = sc_time_stamp();
  std::cout << "Starting " << me << " @ " << now << std::endl;
  now = sc_time_stamp();
  std::cout << "Exiting" << me << " @ " << now << std::endl;
}
