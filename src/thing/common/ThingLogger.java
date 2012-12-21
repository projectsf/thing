package thing.common;
import java.util.logging.*;

public class ThingLogger {
	private static FileHandler fileHandler = null;
 
	public static void init() {
		try {
			fileHandler = new FileHandler("loggerExample.log", false);
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		Logger logger = Logger.getLogger("");
		fileHandler.setFormatter(new SimpleFormatter());
		logger.addHandler(fileHandler);
		logger.setLevel(Level.CONFIG);
	}
}

