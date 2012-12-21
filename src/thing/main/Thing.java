import thing.common.ComponentManager;
public class Thing {

	public static void main (String args[]) {

		//start component manager
		ComponentManager componentManager = new ComponentManager();
		componentManager.start();

		//wait for ever for now
		while(true) {
		}

	}
}
