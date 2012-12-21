package thing.common;
import java.net.*;
import java.nio.*;
import java.io.*;

public class CommandListener extends Component implements Runnable {
	private ServerSocket serverSocket;
	
	public CommandListener() {
	}

	public void start()
	{
		(new Thread(this)).start();
	}

	public void stop()
	{
		System.out.println("Not implemented");
	}

	//this has to be synchronized as well
	public void run() {
		//initialize server socket
		int port = 35000;

		try {
			serverSocket = new ServerSocket(port);
			System.out.println("CommandListener listening on port: " + port);
		}
		catch (Exception e) {
			e.printStackTrace();
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
				System.out.println("Unable to get: " + commandProcessorName + " from ComponentManager");
				e.printStackTrace();
			}
		
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
