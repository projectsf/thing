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
// File: JetlunHan.hpp
namespace jetlun {
//gsoap hs service name: JetlunHan
//gsoap hs service namespace: urn:JetlunHan
//gsoap hs service location: http://www.grid-net.com/jetlunhan.cgi
//gsoap hs service style: rpc
//gsoap hs service encoding: encoded

typedef std::string xsd__string;
typedef char xsd__byte;
typedef int xsd__int;

class hs__NoResponse
{
};

// Initialize GW Module
class hs__StartGwModuleRequest
{
	public:
	xsd__byte admissionMode;
	xsd__byte size;
};

int hs__startGwModule(hs__StartGwModuleRequest request, hs__NoResponse& response);

int hs__getGwModuleStatus(xsd__int& response);

}

