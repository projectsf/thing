/**
 * Used in socket_main.cpp example
 *
 * @file DomainServerSocket.h
 */
// Definition of the DomainServerSocket class

#ifndef DomainServerSocket_class
#define DomainServerSocket_class

#include "DomainSocket.hpp"


class DomainServerSocket : public DomainSocket
{
 public:

  DomainServerSocket ( int port );
  DomainServerSocket (){};
  virtual ~DomainServerSocket();

  const DomainServerSocket& operator << ( const std::string& ) const;
  const DomainServerSocket& operator >> ( std::string& ) const;

  void accept ( DomainServerSocket& );

};


#endif

