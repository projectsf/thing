/**
 * Used in socket_main.cpp
 *
 * @file DomainServerSocket.cpp
 */

 
// Implementation of the DomainServerSocket class

#include "DomainServerSocket.hpp"
#include "DomainSocketException.hpp"


DomainServerSocket::DomainServerSocket ( int port )
{
  if ( ! DomainSocket::create() )
    {
      throw DomainSocketException ( "Could not create server socket." );
    }

  if ( ! DomainSocket::bind ( port ) )
    {
      throw DomainSocketException ( "Could not bind to port." );
    }

  if ( ! DomainSocket::listen() )
    {
      throw DomainSocketException ( "Could not listen to socket." );
    }

}

DomainServerSocket::~DomainServerSocket()
{
}


const DomainServerSocket& DomainServerSocket::operator << ( const std::string& s ) const
{
  if ( ! DomainSocket::send ( s ) )
    {
      throw DomainSocketException ( "Could not write to socket." );
    }

  return *this;

}


const DomainServerSocket& DomainServerSocket::operator >> ( std::string& s ) const
{
  if ( ! DomainSocket::recv ( s ) )
    {
      throw DomainSocketException ( "Could not read from socket." );
    }

  return *this;
}

void DomainServerSocket::accept ( DomainServerSocket& sock )
{
  if ( ! DomainSocket::accept ( sock ) )
    {
      throw DomainSocketException ( "Could not accept socket." );
    }
}

