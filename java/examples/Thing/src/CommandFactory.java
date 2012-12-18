import java.util.HashMap;

public class CommandFactory {
	private static HashMap<String, Command> commandFactories = new HashMap<String, Command>();
	private static CommandFactory instance = null;

	public static void register(String commandIdentifier, Command command)
	{
		commandFactories.put(commandIdentifier, command);
	}

	public Command create(String commandIdentifier)
	{
		return commandFactories.get(commandIdentifier).create();
	}

	public static CommandFactory instance() {
		if (instance == null) {
			instance = new CommandFactory();
		}
		return instance;
	}
	
}
