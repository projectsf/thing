/****************************************************************************
 *             GRID NET, INC. CONFIDENTIAL
 *
 * The source code contained or described herein and all documents related
 * to the source code ("Material") are owned by Grid Net, Inc. or its
 * suppliers or licensors. Title to the Material remains with Grid Net or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Grid Net or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and treaty
 * provisions. No part of the Material may be used, copied, reproduced, modified,
 * published, uploaded, posted, transmitted, distributed, or disclosed in any way
 * without the prior express written permission of Grid Net, Inc.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Material, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Grid Net, Inc. in writing.
 *
 *      Copyright (c) 2006-2008 Grid Net, Inc.  All Rights Reserved.
 *
 ****************************************************************************/
//File: hanClient.cpp
#include "jetlunH.h"
#include "JetlunHan.nsmap"

#include <iostream>

#include "hanClient.hpp"

int main()
{
	std::string netIfName("eth1");

	jetlun::HanClient client(netIfName);

	// Make gSoap requests
	return 0;
}

namespace jetlun
{

HanClient::HanClient(const std::string& netIfName)
{
	std::cout << "netIfName = " << netIfName.c_str() << std::endl;
	
	if (createUdpSocket(netIfName) < 0)
	{
		fprintf(stderr, "Creation of UDP socket failed\n");
	}
}

HanClient::~HanClient()
{
}

int HanClient::createUdpSocket(const std::string& netIfName)
{
	std::cout << "netIfName = " << netIfName.c_str() << std::endl;

	// Allocate UDP socket
	int sock = socket(PF_INET, SOCK_DGRAM, 0); // IPv4, datagram, default protocol
	if (sock == -1)
	{
		fprintf(stderr, "Error allocating UDP socket: %s\n", strerror(errno));
	}
	
	// Set up destination socket address
	struct sockaddr_in destSockAddr;
	if (getSocketAddress(netIfName, sock, destSockAddr) < 0)
	{
		fprintf(stderr, "Closing UDP socket\n");
		// Close socket
		if (sock > 0)
		{
			if (close(sock) == -1)
			{
				fprintf(stderr, "Error closing UDP socket: %s\n", strerror(errno));
			}
		}
	}

	return sock;
}

int HanClient::getSocketAddress(const std::string& netIfName, int sock, struct sockaddr_in& sockAddr)
{
	std::cout << "getSocketAddress " << netIfName.c_str() << std::endl;
	static int SERVER_PORT = 8080;
	static std::string SERVER_IP("127.0.0.1");

	int status = 0; // success

	sock; // not used yet

	// Set up socket address
	bzero(&sockAddr, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP.c_str(), &sockAddr.sin_addr);

	return status;
}

}

