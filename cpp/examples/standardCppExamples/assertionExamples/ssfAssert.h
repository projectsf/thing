/**
 * Used in assertionExample.cpp
 * @file ssfAssert.h
 */

#include <cstdlib>
#ifndef NDEBUG
# define ASSERT( isOK, message ) \
 if ( !isOK ) \
 { \
   (void)printf("ERROR!! Assert '%s' failed on line %d" \
   "in file '%s'\n%s\n", #isOK, __LINE__, __FILE__, #message); \
   abort(); \
 }
#else
  #define ASSERT( unused, message ) do {} while ( false )
#endif
