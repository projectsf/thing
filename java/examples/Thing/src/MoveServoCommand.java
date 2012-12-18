public class MoveServoCommand extends Command {
    static {
        CommandFactory.instance().register("MoveServoCommand", new MoveServoCommand());
    }

	public void run() {
		System.out.println("Moved servo suckers");
	}
	
	public Command create() {
		return new MoveServoCommand();
	}
	
}
