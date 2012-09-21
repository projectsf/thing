#include <systemc.h>
#include <cmath>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
using namespace sc_dt;



class Block
{
public:

	Block(bool isFixed, unsigned int bitWidth = 1)
	  : m_fxCxtSwitch( (isFixed ? SC_ON:SC_OFF) ),
	    m_fxCxt( m_fxCxtSwitch ),
	    m_nodeOne( bitWidth, 1 ),
	    m_vResults(),
	    SEED(42),
	    m_generator(SEED),
	    m_distribution(-1,1),
      m_noiseGenerator(m_generator, m_distribution)
	{
		try {
		  m_vResults.reserve(static_cast<unsigned int>(1e6));
		}
		catch(std::exception& exc)
		{
			std::cout << "Caught: " << exc.what() << std::endl;
			throw;
		}
	}

  void execute()
  {
  	double temp = m_noiseGenerator();
  	m_nodeOne = temp;
  	m_vResults.push_back(m_nodeOne);
  }
  	
  const std::vector<double>& getResults() const
  {
  	return m_vResults;
  }
  
  void printResults() const
  {
  	for(std::vector<double>::const_iterator iter = m_vResults.begin();
  	    iter != m_vResults.end();
  	    ++iter)
  	{
  		std::cout << *iter << " ";
  	}
  	std::cout << std::endl;
  }
  
 private:
   sc_fxcast_switch m_fxCxtSwitch;
	 sc_fxcast_context m_fxCxt;
	 sc_fix m_nodeOne;
	 std::vector<double> m_vResults;
	 const int32_t SEED;
	 boost::rand48 m_generator;
	 boost::uniform_real<> m_distribution;
   boost::variate_generator<boost::rand48&, boost::uniform_real<> > m_noiseGenerator;
};

double calcSqnr(const std::vector<double>& a, const std::vector<double>& b)
{
  if( a.size() != b.size() ) {
    std::cout << "Size mismatch" << std::endl;
    return 0.0;
  }
  double error = 0.0;
  for(unsigned int ii = 0; ii<a.size(); ++ii) {
  	error += std::abs(a[ii]-b[ii]);
  }
  
  //looking for mean squared error
  error = error / a.size() ;

  return 10*log(error);
}

int main(int argc, char* argv[])
{
	unsigned int initialBitWidth = 1;
	unsigned int finalBitWidth = 16;
  unsigned int numTests = static_cast<unsigned int>(1e6);
	
	std::cout << "Sqnr for Quant Scheme : " << std::endl;
	
	for(unsigned int ii=initialBitWidth; ii <= finalBitWidth; ++ii) {
		bool isFixed = true;
		bool isNotFixed = false;	  
		Block blockA(isFixed, ii);
	  Block blockB(isNotFixed);

	
		for(int jj=0;jj<numTests;++jj){
			blockA.execute();
			blockB.execute();
		}
		
 	  std::cout << ii+1 << " totalBits, 1 integer bit (sign) :" << calcSqnr( (blockA.getResults()), (blockB.getResults()) ) << std::endl;
	}
}
