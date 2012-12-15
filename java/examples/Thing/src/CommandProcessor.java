import java.util.concurrent.LinkedBlockingQueue;

//is linkedblockingqueue include synchronization?

public class CommandProcessor extends Thread implements Cloneable {
	private LinkedBlockingQueue<String> messages;
	
	public CommandProcessor() {
		messages = new LinkedBlockingQueue<String>();
	}

	//this has to be synchronized as well
	public void run() {
		while(true) {
			try {
				String message = messages.take();
				System.out.println("Processing message: "+message);
			} 
			catch (InterruptedException e) {
				System.out.println("interrupted");
			}
		}
	}

	//this has to be synchronized if we end up making server multithreaded
	public void dispatch(String message) {
		messages.offer(message);
	}

	
}
