package thing.common;
import java.util.HashMap;

public class ComponentManager {
	private HashMap<String, Component> components = new HashMap<String, Component>();

	public void start()
	{
		//load all commands in here for now
		try {
			Class.forName("thing.common.MoveServoCommand");
		}
		catch (ClassNotFoundException e) {
			System.out.println("MoveServoCommand not found");
		}             

        CustomClassLoader classLoader = new CustomClassLoader();
		try {
        	Class aClass = classLoader.loadClass("thing.common.CommandProcessor");
			CommandProcessor commandProcessor = (CommandProcessor)aClass.newInstance();
			components.put("CommandProcessor", commandProcessor);

			//hard code this for now until i figure out how to pass in args to custom ctor
			components.put("CommandListener", new CommandListener(commandProcessor));
		}
		catch (ClassNotFoundException e) {
			System.out.println("Not found suckas");
		}
		catch (InstantiationException e) {
			System.out.println("Can't instantiate");
		}
		catch (IllegalAccessException e) {
			System.out.println("illegal access");
		}
		catch (ClassCastException e) {
			System.out.println("class cast exception: " + e);
		}

		//start all components in container
		for (HashMap.Entry<String, Component> entry : components.entrySet())
		{
			System.out.println("Starting: " + entry.getKey());
			entry.getValue().start();
		}
	}

	public void upgrade(String componentName)
	{
	}
}
