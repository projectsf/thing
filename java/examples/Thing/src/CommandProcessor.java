import java.util.ArrayList;

//scoped lock java?

public class CommandProcessor extends Thread implements Cloneable {
	ArrayList<String> messages;
	
	public CommandProcessor() {
		messages = new ArrayList();
	}

	//this has to be synchronized as well
	public synchronized void run() {
		while(true) {
			try {
				System.out.println("waiting");
				wait();
				System.out.println("received new message");
			} 
			catch (InterruptedException e) {
				System.out.println("interrupted");
			}
		}
	}

	//this has to be synchronized if we end up making server multithreaded
	public synchronized void dispatch(String message) {
		messages.add(message);
		System.out.println("messages size: "+messages.size());
		notifyAll();
	}

	
}
