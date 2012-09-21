class Client : public Runnable
		
{
	public:
		Client::Client(string& name) : name(name), thread(name, this)
		{
		}
		
		

		Client::start()
		{
			cout << name << " Started ... " << endl;
			thread.start();
		}
		
		Client::run()
		{
			unsigned int sleepTime;
			
			sleepTime = rand();
			sleep(sleepTime):
			Message messageOne("messageOne");
			ActiveObject->getInstance()->publish(messageOne);
			
			sleepTime = rand();
			sleep(sleepTime):
			Message messageTwo("messageThree");
			FutureSharedPointer futureTwo = ActiveObject->getInstance()->publish(messageTwo);
			
			sleepTime = rand();
			sleep(sleepTime):
			Message messageThree("messageThree");
			FutureSharedPointer futureThree = ActiveObject->getInstance()->publish(messageThree);
			
			//block on returning results for futures
			sleepTime = rand();
			sleep(sleepTime):
			Message messageTwo = futureTwo.getResult();
			Message messageThree = futureThree.getResult();
		}
		
	private:
		string name;
		Thread thread;
};


int main()
{
	typedef shared_ptr<Client> ClientSharedPointer;
	typedef vector<ClientSharedPointer> ClientVector;
	typedef vector<ClientSharedPointer>::iterator ClientVectorIterator;
	typedef vector<ClientSharedPointer>::iterator ClientVectorConstIterator;
	
	unsigned int numberClients = 5;
	
	for (unsigned int ii = 0; ii < numberClients; ++ii)
	{
		clients.push_back(new Client(&activeObject));
	}
	
	for (ClientVectorIterator iter = clients.begin(); iter != clients.end(); ++iter)
	{
		iter->start();
	}
	
	sleep(100);

}