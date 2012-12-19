import java.util.HashMap;

public class ComponentManager {
	private HashMap<String, Component> components = new HashMap<String, Component>();

	public void start()
	{
		//load all commands in here for now
		try {
			Class.forName("MoveServoCommand");
		}
		catch (ClassNotFoundException e) {
		}             

		//hardcode components for now
		CommandProcessor commandProcessor = new CommandProcessor();
		components.put("CommandProcessor", commandProcessor);
		components.put("CommandListener", new CommandListener(commandProcessor));

		//start all components in container
		for (HashMap.Entry<String, Component> entry : components.entrySet())
		{
			System.out.println("Starting: " + entry.getKey());
			entry.getValue().start();
		}
	}
}
