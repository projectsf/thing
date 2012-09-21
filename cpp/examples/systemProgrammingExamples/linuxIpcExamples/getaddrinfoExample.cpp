/**
 * Example looks at using getaddrinfo
 *
 * @file getaddrinfoExample.cpp
 */
 
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <string>
#include <errno.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char *argv[])
{

	string host("opah");
	string service;
	struct addrinfo hint;
    struct addrinfo* result;
	const char *addr;
	char abuf[INET_ADDRSTRLEN];
	struct sockaddr_in* sinp;
	struct in_addr destAddr;
	

    memset(&hint, 0, sizeof(hint));
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_family = AF_INET;

    int error =  getaddrinfo(host.c_str(), service.c_str(), &hint, &result);

	if (error)
	{
		cerr << gai_strerror(errno) << endl;
	}
	else
	{
		cout << "Result: " << endl;
		cout << "Port :" << ntohs(reinterpret_cast<sockaddr_in*>(result->ai_addr)->sin_port) << endl;
		sinp =  (struct sockaddr_in*)result->ai_addr;
		cout << "Sockaddr : " << sinp->sin_addr.s_addr << endl;;
		addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
		cout << "String Addr: " << addr << endl;

		memcpy((char *)&(destAddr.s_addr), &sinp->sin_addr.s_addr, sizeof(sinp->sin_addr.s_addr));
		cout << "Destination Sockaddr : " << destAddr.s_addr << endl;
		
	}

	//free result returned by function
	freeaddrinfo(result);

}
