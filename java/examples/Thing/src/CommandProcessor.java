import java.util.concurrent.LinkedBlockingQueue;

//is linkedblockingqueue include synchronization?

public class CommandProcessor extends Component implements Runnable {
	private LinkedBlockingQueue<String> messages;
	
	public CommandProcessor() {
		messages = new LinkedBlockingQueue<String>();
	}

	public void start()
	{
		(new Thread(this)).start();
	}

	public void stop()
	{
		System.out.println("Not implemented");
	}

	//this has to be synchronized as well
	public void run() {
		while(true) {
			try {
				String message = messages.take();

				System.out.println("Processing message: "+message);

				//message is simply identifier at this point
				//build command object from it and run
				Command command = CommandFactory.instance().create(message);

				//try to run it
				command.run();
			
			} 
			catch (InterruptedException e) {
				System.out.println("interrupted");
			}
		}
	}

	//this has to be synchronized if we end up making server multithreaded
	public void dispatch(String message) {
		try {
			messages.put(message);
		}
		catch (InterruptedException e) {
		}
	}

	
}
