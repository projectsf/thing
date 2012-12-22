package thing.common;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.logging.*;

public class CommandProcessor extends Component implements Runnable {
	private LinkedBlockingQueue<String> messages;
    private static final Logger log = Logger.getLogger(CommandProcessor.class.getName());
	
	public CommandProcessor() {
		messages = new LinkedBlockingQueue<String>();
	}

	public void start()
	{
		(new Thread(this)).start();
	}

	public void stop()
	{
		log.warning("Not implemented");
	}

	//this has to be synchronized as well
	public void run() {
		while(true) {
			try {
				String message = messages.take();

				log.fine("Processing message: "+message);

				//message is simply identifier at this point
				//build command object from it and run
				Command command = CommandFactory.instance().create(message);

				//try to run it
				command.run();
			
			} 
			catch (InterruptedException e) {
				log.fine("interrupted");
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
