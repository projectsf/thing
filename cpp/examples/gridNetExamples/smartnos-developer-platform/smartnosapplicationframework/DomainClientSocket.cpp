/**
 * Used in socket_main.cpp
 *
 * @file DomainClientSocket.cpp
 */

// Implementation of the DomainClientSocket class

#include "DomainClientSocket.hpp"
#include "DomainSocketException.hpp"


DomainClientSocket::DomainClientSocket ( std::string host, int port )
{
  if ( ! DomainSocket::create() )
    {
      throw DomainSocketException ( "Could not create client socket." );
    }

  if ( ! DomainSocket::connect ( host, port ) )
    {
      throw DomainSocketException ( "Could not bind to port." );
    }

}


const DomainClientSocket& DomainClientSocket::operator << ( const std::string& s ) const
{
  if ( ! DomainSocket::send ( s ) )
    {
      throw DomainSocketException ( "Could not write to socket." );
    }

  return *this;

}


const DomainClientSocket& DomainClientSocket::operator >> ( std::string& s ) const
{
  if ( ! DomainSocket::recv ( s ) )
    {
      throw DomainSocketException ( "Could not read from socket." );
    }

  return *this;
}

