/**
 * Used in socket_main.cpp example
 *
 * @file DomainSocketException.h
 */

// DomainSocketException class


#ifndef DomainSocketException_class
#define DomainSocketException_class

#include <string>

class DomainSocketException
{
 public:
  DomainSocketException ( std::string s ) : m_s ( s ) {};
  ~DomainSocketException (){};

  std::string description() { return m_s; }

 private:

  std::string m_s;

};

#endif
