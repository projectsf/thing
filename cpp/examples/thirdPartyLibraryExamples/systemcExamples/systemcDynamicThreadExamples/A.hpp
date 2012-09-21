

SC_MODULE(A) {
  SC_CTOR(A) {
    SC_THREAD(mainThread);
  }
  void mainThread();
  void dynamicThread();
};


void A::main_thread()
{
  std::cout << "Starting " << name() << std::endl;
  wait(1,SC_NS)
  sc_process_handle = sc_spawn((sc_bind(&A::dynamicThread, this),"d1"));
  wait(3,SC_NS);
  sc_process_handle = sc_spawn((sc_bind(&A::dynamicThread, this),"d2"));
  h1.wait();
  std::cout << "h1 finished" << std::endl;
}

void A::dynamicThread()
{
  char* me = sc_get_curr_process_handle()->name();
  sc_time now = sc_time_stamp();
  std::cout << "Starting " << me << " @ " << now << std::endl;
  now = sc_time_stampe();
  std::cout << "Exiting" << me << " @ " << now << std::endl;
}