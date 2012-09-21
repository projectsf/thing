/** Example investigating whether itpp's RS encoder
 *
 * @file itppReedSolomonExample.cpp
 */


#include <itpp/itcomm.h>

using namespace itpp;

//These lines are needed for use of cout and endl
using std::cout;
using std::endl;

int main()
{

  //Scalars and vectors:
  bvec uncoded_bits, coded_bits;

  bvec phyHeader = "0 0 0 0 0 0 0 0 0 1 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0";
  bvec scrambledData = "1 0 0 1 1 1 0 1 0 0 1 1 0 1 1 1 0 1 0 0 0 0 0 0 1 0 0 1 0 1 1 1 1 1 0 0 0 0 1 0 1 1 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 0 1 0 1 1 0 1 0 0 0 0 0 1 0 0 1 1 1 1 1 1 0 1 1 0 1 1 1 0 1 0 0 1 1 1 1 1 1";
  bvec reorderedInput = "0 0 0 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 1 0 0 1 1 1 1 0 1 1 0 0 0 0 0 0 0 0 1 0 1 1 1 0 1 0 0 1 0 1 0 0 0 0 1 1 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 0 0 1 1 0 1 0 1 1 0 1 0 0 0 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 1 1 1 1 0 0";
  bvec expectedResults = "1 1 1 0 1 0 0 0 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 1 0 0 1 0 0 1 1 1 1 1 0 1 0 1 1 1 1 1 0 0 1 0 0 0";

      
  //Set parameters:
  int m = 8;                //Reed-Solomon parameter m
  int t = 6;                //Reed-Solomon parameter t
  int k = round_i(pow(2.0,m))-1-2*t;
  int numBits = m * k;

  cout << "RS m: " << m << endl;
  cout << "RS t: " << t << endl;

  //Classes:
  uncoded_bits = randb(256);
  Reed_Solomon reed_solomon(m,t);

  coded_bits = reed_solomon.encode(uncoded_bits);
  cout << "Size of output : " << coded_bits.size()  << " bits" << std::endl << "                 " << coded_bits.size()/8 << " bytes" << std::endl;


  //Exit program:
  return 0;

}

