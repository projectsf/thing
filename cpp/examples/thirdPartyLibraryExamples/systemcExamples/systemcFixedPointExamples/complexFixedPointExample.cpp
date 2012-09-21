#define SC_INCLUDE_FX

#include <systemc.h>
#include <complex>
#include <cmath>

using namespace sc_dt;




int main(int argc, char* argv[])
{

  double real(2.0), imag(3.0);
  sc_fix fxReal(7,7), fxImag(7,7);
  fxReal = real;
  fxImag = imag;

  //investigating quantization
  const unsigned int NUM_ITERATIONS = 30;
  for (unsigned ii=0; ii< NUM_ITERATIONS; ++ii) {
    double zero = 0.0;
    double maxPos = rand() * pow(2,-8);
    double maxNeg = maxPos * -1.0;
    sc_fix zeroFx(2,-4, SC_SAT_SYM), maxPosFx(2,-4), maxNegFx(2,-4);
    sc_fix zeroFxTwo(8,2), maxPosFxTwo(8,2), maxNegFxTwo(8,2);
    zeroFx = zero;
    maxPosFx = maxPos;
    maxNegFx = maxNeg;
    zeroFxTwo = zeroFx;
    maxPosFxTwo = maxPosFx;
    maxNegFxTwo = maxNegFx;
    //std::cout << "Zero " << zeroFx.to_bin() << std::endl;
    std::cout << "MaxPos: " << maxPosFxTwo.to_bin() << std::endl;
    std::cout << "MaxNeg: " << maxNegFxTwo.to_bin() << std::endl;
  }


  
  std::complex<sc_fix> fixCxOne(fxReal,fxImag);
  std::complex<sc_fix> fixCxTwo(real,imag);
  std::complex<sc_fix> fixCxThree( sc_fix(7,-5), sc_fix(7,-5) );

  //std::cout << "fixCxOne: " << fixCxOne << std::endl;
  //std::cout << "fixCxTwo: " << fixCxTwo << std::endl;
  //std::cout << "fixCxThree: " << fixCxThree << std::endl;
}
