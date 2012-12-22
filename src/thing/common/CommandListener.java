package thing.common;
import java.net.*;
import java.nio.*;
import java.io.*;
import java.util.logging.*;

public class CommandListener extends Component implements Runnable {
	private ServerSocket serverSocket;
	private static final Logger log = Logger.getLogger(CommandListener.class.getName());
	
	public CommandListener() {
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
		//initialize server socket
		int port = 35000;

		try {
			serverSocket = new ServerSocket(port);
			log.info("CommandListener listening on port: " + port);
		}
		catch (Exception e) {
			log.severe(e.getMessage());
		}

		while (true)
		{
			listen();
		}

	}
	public void listen() {
		try {

			//get input stream from socket
			Socket socket = serverSocket.accept();
			InputStream socketInputStream = socket.getInputStream();
		
			//how to read input stream indefinitely
			int value;
			ByteBuffer buffer = ByteBuffer.allocate(4092);
			int count = 0;
			while ((value = socketInputStream.read()) != 0) {
				buffer.put((byte)value);
				count++;
			}

			//convert byte buffer to string
			String message = new String(buffer.array(), 0, count);

			//get component from component manager
			String commandProcessorName = "thing.common.CommandProcessor";
			try {
				CommandProcessor commandProcessor = (CommandProcessor)ComponentManager.getComponent(commandProcessorName);
				commandProcessor.dispatch(message);

			}
			catch (Exception e) {
				log.severe(e.getMessage());
			}
		
		}
		catch (Exception e) {
			log.severe(e.getMessage());
		}
	}
}
