import java.net.*;
import java.util.ArrayList;
import java.nio.*;
import java.io.*;


//scoped lock java?

public class CommandProcessor extends Thread {
	ArrayList<String> messages;
	ServerSocket serverSocket;
	
	public CommandProcessor() {

		//initialize server socket
		int port = 35000;

		try {
			serverSocket = new ServerSocket(port);
			System.out.println("Listening on port: "+port);
		}
		catch (Exception e) {
			e.printStackTrace();
		}

		listen();
	}

	//this has to be synchronized as well
	public synchronized void run() {
		while(true) {
			try {
				wait();
				System.out.println("Received new message");
			} 
			catch (InterruptedException e) {
			}
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
			System.out.println("Received values:"+buffer);
		
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	//this has to be synchronized if we end up making server multithreaded
	public synchronized void dispatch(String message) {
		messages.add(message);
		notifyAll();
	}

	
}
