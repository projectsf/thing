/**
 * Used in socket_main.cpp example
 *
 * @file simple_client_main.cpp
 */
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, char* argv[] )
{
	try
	{
		ClientSocket client_socket ( "10.1.1.170", 4400 );
		std::string reply;

		try
		{
			while(1)
			{
				std::string message;
				std::cout << "Please enter a message that can be routed to the server." << std::endl;
				std::cin >> message;
				client_socket << message;
				client_socket >> reply;
				std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
			}
		}

		catch ( SocketException& ) 
		{
		}

		std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
	}

	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\n";
	}

return 0;
}
