import java.net.*;
import java.nio.*;
import java.io.*;


public class CommandListener extends Thread {
	private ServerSocket serverSocket;
	private CommandProcessor commandProcessor;
	
	public CommandListener(CommandProcessor commandProcessor) {

		this.commandProcessor = commandProcessor;

		//initialize server socket
		int port = 35000;

		try {
			serverSocket = new ServerSocket(port);
			System.out.println("Listening on port: "+port);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	//this has to be synchronized as well
	public void run() {
		//start up listening socket

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
			while ((value = socketInputStream.read()) != 0) {
				buffer.putInt((char)value);
			}

			//convert byte buffer to string
			String message = new String(buffer.array());
			commandProcessor.dispatch(message);
		
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
