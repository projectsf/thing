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
 *      Copyright (c) 2006-2009 Grid Net, Inc.  All Rights Reserved.
 *
 *  $URL: svn://dev.grid-net.com/mainline/trunk/server/webservice/PolicyNetCA.h $
 *  $Rev: 25694 $
 *  $Author: florian $
 *  $Date: 2010-02-01 17:04:18 -0800 (Mon, 01 Feb 2010) $
 *
 ****************************************************************************/

//gsoap policynet service documentation: GRID NET, INC. CONFIDENTIAL <p />The source code contained or described herein and all documents related to the source code ("Material") are owned by Grid Net, Inc. or its suppliers or licensors. Title to the Material remains with Grid Net or its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of Grid Net or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed, or disclosed in any way without the prior express written permission of Grid Net, Inc.  No license under any patent, copyright, trade secret or other intellectual property right is granted to or conferred upon you by disclosure or delivery of the Material, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Grid Net, Inc. in writing.<p />  Copyright (c) 2006-2010 Grid Net, Inc.  All Rights Reserved.
//gsoap policynet service name: PolicyNetCA
//gsoap policynet service style: document
//gsoap policynet schema namespace: urn:policynet/0.0.0
//gsoap policynet service namespace: urn:policynet/0.0.0
//gsoapopt in


namespace policynetca
{

#import "soap12.h"
#import "xop.h"
#import "xmime5.h"
#import "stlvector.h"

#import "env.h"

typedef unsigned int    xsd__positiveInteger;
typedef std::string     xsd__string;
typedef std::string		policynet__PKCS10;
typedef std::string     policynet__UserName "^[a-zA-Z0-9_]{3,10}$";
typedef std::string     policynet__LoginPassword "^[^ ]{8,18}$";
typedef std::string     xsd__dateTime "^[12][0-9]{3}-(0[1-9]|1[0-2])-([0-2][0-9]|3[01])T([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]([+-](0[0-9]|1[0-4]):[0-5][0-9]|Z)?$";

struct policynet__BinaryData
{
	_xop__Include xop__Include;
	@char *xmime5__contentType;
};

class xsd__base64Binary
{
   public:
   unsigned char *__ptr;
   int __size;
};

enum policynet__PKIStatus
{
	Accepted = 0,
	GrantedWithMods = 1,
	Rejection = 2, 
	Waiting = 3, // the request  has not yet been processed
	RevocationWarning = 4, // this message contains a warning that a revocation is imminent
	RevocationNotification = 5 //notification that a revocation has occurred

};

enum policynet__PKIFailureInfo
{
	badAlg              =0, // unrecognized or unsupported Algorithm Identifier
	badMessageCheck     =1, // integrity check failed (e.g., signature did not verify)
	badCertid           =2,
	badDataFormat       =3, // the data submitted has the wrong format
	badPOP              =4, // the proof-of-possession failed
	certRevoked         =5, // the certificate has already been revoked
	certConfirmed       =6, // the certificate has already been confirmed
	transactionIdInUse  =7, // the transaction identifier is already in use
	notAuthorized       =8, // the sender was not authorized to make the preceding request or perform the preceding action
	systemUnavail       =9, // the request cannot be handled due to system unavailability
	systemFailure       =10 //the request cannot be handled due to system failure
};

class policynet__PKIStatusInfo
{
public:
	enum policynet__PKIStatus			Status;
	enum policynet__PKIFailureInfo*		FailureInfo;
};


class policynet__CertId
{
public:
	xsd__string				Issuer;
	xsd__string				SerialNumber;
};

class policynet__SGDevice
{
public:
	xsd__string	McUID;
};

enum policynet__PNService
{
    PolicyServer = 1,
    Webservice,
    OOB,
    MDM,
    RA,
    CA,
    AAA,
    UI,
    OCSP,
    DHCP,
    DeviceFileImport,
    Database,
    Device
};

union policynet__EETypeUnion
{
        policynet__SGDevice*	  Device;
        enum policynet__PNService Service;
};

struct policynet__EndEntityType
{
public:
	int __union;
	union policynet__EETypeUnion EEType;
};


class policynet__PKCSCertificates
{
public:
	std::vector<policynet__PKCS10>	Certificate;
};

class policynet__PKCSDigitalEvenlope
{
	unsigned char					IV[16];
	struct policynet__BinaryData	EncryptedSecretKey;
	struct policynet__BinaryData	EncryptedData;
};

class policynet__CertificateSigning
{
	struct policynet__EndEntityType EndEntity;
	policynet__PKCS10	 CSR;
};

class policynet__CertificateSigningResponse
{
 public:
	policynet__PKIStatusInfo Status;
	xsd__dateTime*						ConfirmWaitTime; // //gsoap policynet service type-documentation: CertificateSigningResponse.ConfirmWaitTime This is used to inform the EE how long it intends to wait for the certificate confirmation before revoking the certificate and deleting the transaction
	policynet__PKCSDigitalEvenlope*		POP; //gsoap policynet service type-documentation: CertificateSigningResponse.POP Proof of the private key possession

};

//gsoap policynet service method-header-part: CertificateSigningRequest policynet__LoginUsername
//gsoap policynet service method-header-part: CertificateSigningRequest policynet__LoginPassword
//gsoap policynet service method-header-part: CertificateSigningRequest policynet__TransactionId
//gsoap policynet service method-name: CertificateSigningRequest CertificateSigning
//gsoap policynet service method-action: CertificateSigningRequest CertificateSigning

int policynet__CertificateSigningRequest(policynet__CertificateSigning Request,
										 policynet__CertificateSigningResponse&   Response);


class policynet__CertificateConfirm
{
 public:
	policynet__CertId			CertificateId;
	struct policynet__BinaryData		CertificateHash;
};

class policynet__CertificateConfirmResponse
{
public:
	policynet__PKIStatusInfo Status;
};

//gsoap policynet service method-header-part: CertificateConfirmRequest policynet__LoginUsername
//gsoap policynet service method-header-part: CertificateConfirmRequest policynet__LoginPassword
//gsoap policynet service method-header-part: CertificateConfirmRequest policynet__TransactionId
//gsoap policynet service method-name: CertificateConfirmRequest CertificateConfirm
//gsoap policynet service method-action: CertificateConfirmRequest CertificateConfirm

int policynet__CertificateConfirmRequest(policynet__CertificateConfirm Confirm,
										 policynet__CertificateConfirmResponse&   Response);


enum policynet__CRLReason
{
	Unspecified = 0,
	KeyCompromise,
	CACompromise,
	AffiliationChanged, 
	Superseded, 
	CessationOfOperation, 
	CertificateHold,
	RemoveFromCRL,
	PrivilegeWithdrawn
};

class policynet__CertificateRevocation
{
 public:
	policynet__CertId				CertId;
	enum policynet__CRLReason		Reason;
	xsd__dateTime					InvalidityDate;
};


class policynet__CertificateRevocationResponse
{
 public:
	policynet__PKIStatusInfo Status;
};

//gsoap policynet service method-header-part: CertificateRevocationRequest policynet__LoginUsername
//gsoap policynet service method-header-part: CertificateRevocationRequest policynet__LoginPassword
//gsoap policynet service method-header-part: CertificateRevocationRequest policynet__TransactionId
//gsoap policynet service method-name: CertificateRevocationRequest CertificateRevocation
//gsoap policynet service method-action: CertificateRevocationRequest CertificateRevocation

int policynet__CertificateRevocationRequest(policynet__PKCS10							SenderCertificate,
											policynet__CertificateRevocation 			CertRev,
											policynet__CertificateRevocationResponse&   Response);


class policynet__CertificateRevocationListResponse
{
 public:
	policynet__PKIStatusInfo Status;
	char*					 CRL;
};

//gsoap policynet service method-header-part: CertificateRevocationListRequest policynet__LoginUsername
//gsoap policynet service method-header-part: CertificateRevocationListRequest policynet__LoginPassword
//gsoap policynet service method-header-part: CertificateRevocationListRequest policynet__TransactionId
//gsoap policynet service method-name: CertificateRevocationListRequest CertificateRevocationList
//gsoap policynet service method-action: CertificateRevocationListRequest CertificateRevocationList

int policynet__CertificateRevocationListRequest(void*,
												policynet__CertificateRevocationListResponse&   Response);


}
