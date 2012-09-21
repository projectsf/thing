/**
 * Used in socket_main.cpp example
 *
 * @file simple_server_main.cpp
 */

#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 4400 );

      while ( true )
	{

	  while ( true )
          {
	    ServerSocket new_sock;
            server.accept ( new_sock );
            int pid = fork();

            switch ( pid )
            {
              case -1 :
              {
                std::cout << "fork error" << std::endl;
                break;
              }
              case 0 :
              {
                std::cout << "I'm the child" << std::endl;
   	        try
  	        {
	          while ( true )
	    	  {
		    std::string data;
		    new_sock >> data;
                    std::cout << "Child Server received the following message: " << data << std::endl;
		    new_sock << data;
		  }
	        }
	        catch ( SocketException& ) {}
                break;
              }

              default : 
              {
                std::cout << "I'm the parent" << std::endl;
                break;
              }
            }

          }

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}

