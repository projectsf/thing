/**
 * Used in socket_main.cpp example
 *
 * @file DomainClientSocket.h
 */
// Definition of the DomainClientSocket class

#ifndef DomainClientSocket_class
#define DomainClientSocket_class

#include "DomainSocket.hpp"


class DomainClientSocket : public DomainSocket
{
 public:

  DomainClientSocket ( std::string host, int port );
  virtual ~DomainClientSocket(){};

  const DomainClientSocket& operator << ( const std::string& ) const;
  const DomainClientSocket& operator >> ( std::string& ) const;

};


#endif
