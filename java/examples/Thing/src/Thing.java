
public class Thing {
	public static void main (String args[]) {
		System.out.println("Thing says hello");

		//start command processor
		CommandProcessor commandProcessor = new CommandProcessor();
		commandProcessor.start();

		//start command listener 
		CommandListener commandListener = new CommandListener(commandProcessor);
		commandListener.start();

		//wait for command processor to join
		try {
			commandProcessor.join();
		}
		catch (InterruptedException e)	{
		}

		System.out.println("Thing says goodbye");
	}
}
