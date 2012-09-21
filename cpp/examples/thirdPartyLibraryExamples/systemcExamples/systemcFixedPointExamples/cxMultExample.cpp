/**
 * Example illustrates solution for doing a cxMult using sc_fix
 * types
 *
 * @file cxMultExample.cpp
 */

#include <systemc.h>
#include <complex>
#include <sysc/datatypes/fx/sc_fixed.h>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/normal_distribution.hpp>


using namespace sc_dt;

//documentation in header file
void cxMult(const std::complex<sc_dt::sc_fix>& aIn, const std::complex<sc_dt::sc_fix>& bIn, std::complex<sc_dt::sc_fix>& product)
{
//   std::complex<double> a,b;
//   double acProduct,adProduct,bcProduct,bdProduct;
//   a=aIn;
//   b=bIn;
// 
// 
//     acProduct = a.real() * b.real();
//     adProduct = a.real() * b.imag();
//     bcProduct = a.imag() * b.real();
//     bdProduct = a.imag() * b.imag();
//     product = std::complex<double>(acProduct-bdProduct,bcProduct + adProduct);
    
    //verify aIn and bIn have the same sc_fix settings
    //ASSERT( aIn.real().wl() == bIn.real().wl(), aIn real word length != bIn real word length );
    //ASSERT( aIn.real().iwl() == bIn.real().iwl(), aIn real integer word length != bIn real integer word length );
//     bool isFixed = false;
//     sc_fxcast_switch fxContextSwitch(isFixed ? SC_ON:SC_OFF);
//     sc_fxcast_context fxContext(fxContextSwitch);

    //capture quantization parameters
    int wordLength = aIn.real().wl();
    int integerWordLength = aIn.real().iwl();

    sc_dt::sc_fix acProduct(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    sc_dt::sc_fix adProduct(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    sc_dt::sc_fix bcProduct(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    sc_dt::sc_fix bdProduct(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    sc_dt::sc_fix realDifference(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    sc_dt::sc_fix imagSum(wordLength + 1, integerWordLength + 1, sc_dt::SC_RND, sc_dt::SC_SAT);
    

    acProduct = aIn.real() * bIn.real();
    adProduct = aIn.real() * bIn.imag();
    bcProduct = aIn.imag() * bIn.real();
    bdProduct = aIn.imag() * bIn.imag();
    realDifference = acProduct-bdProduct;
    imagSum = bcProduct + adProduct;
    product = std::complex<double>(realDifference,imagSum);
}

int main()
{
  const int SEED = 42;
  boost::rand48 generator(SEED);
  boost::uniform_real<> distribution(-1,1);
  boost::variate_generator<boost::rand48&, boost::uniform_real<> > noiseGenerator(generator, distribution);
  const unsigned int NUM_ITERATIONS = 1;
  bool isFixed = false;
  sc_fxcast_switch fxContextSwitch(isFixed ? SC_ON:SC_OFF);
  sc_fxcast_context fxContext(fxContextSwitch);

  for(unsigned int ii=0;ii<NUM_ITERATIONS;++ii) {
    std::complex<double> cxA(noiseGenerator(), noiseGenerator());
    std::complex<double> cxB(noiseGenerator(), noiseGenerator());
    std::complex<sc_fix> fxCxA(sc_fix(8,1,SC_RND_INF,SC_SAT_SYM),sc_fix(8,1,SC_RND_INF,SC_SAT_SYM));
    std::complex<sc_fix> fxCxB(sc_fix(8,1,SC_RND_INF,SC_SAT_SYM),sc_fix(8,1,SC_RND_INF,SC_SAT_SYM));
    std::complex<sc_fix> fxCxY(sc_fix(9,2,SC_RND_INF,SC_SAT_SYM),sc_fix(9,2,SC_RND_INF,SC_SAT_SYM));
    fxCxA = cxA;
    fxCxB = cxB;
    cxMult(fxCxA,fxCxB,fxCxY);
    std::cout << "Real CxA = " << cxA << " Real CxB= " << cxB << std::endl;
    std::cout << "FxCxA = " << fxCxA << " FxCxB = " << fxCxB << std::endl;
    std::cout << "Real result = " << cxA*cxB << std::endl;
    std::cout << "Fx result = " << fxCxY.real().to_string() << "+" << fxCxY.imag().to_string() << std::endl;
  }
}

