#define SC_INCLUDE_FX

#include <systemc.h>
#include <cmath>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <vector>
#include <map>

using namespace sc_dt;



class Block
{
  public:

    /**
     * Block constructor
     *
     * Constructor first sets m_fxCxtSwitch
     * to be either SC_ON or SC_OFF depending
     * on the isFixed argument.  <br>
     * It then assigns that value to
     * a SystemC fixed point context <br>
     * Next the m_nodeOne is constructed to match
     * the bitWidth argument of the constructor.
     * It is assumed that all values are 1 integer
     * bit (sign) and the rest fractional.
     *
     * The constructor body attempts to reserve
     * enough memory to meet the test requirements
     * An exception will be rethrown if caught.
     */
    Block(bool isFixed, unsigned int bitWidth = 1)
  : m_fxCxtSwitch( (isFixed ? SC_ON:SC_OFF) ),
    m_fxCxt( m_fxCxtSwitch ),
    m_nodeOne( bitWidth, 1 )
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

    void setNewValue(double newValue)
    {
      m_newValue = newValue;
    }

    /**
     * Clears the m_vResults vector
     */
    void clearVector()
    {
      m_vResults.clear();
    }

    /**
     * Block casts the m_newValue to the fixed point type through assignment
     */
    void execute()
    {
      m_nodeOne = m_newValue;
      m_vResults.push_back(m_nodeOne);
    }

    /**
     * Returns the m_vResults vector
     */
    const std::vector<double>& getResults() const
    {
      return m_vResults;
    }
  
  private:
    sc_fxcast_switch m_fxCxtSwitch;
    sc_fxcast_context m_fxCxt;
    sc_fix m_nodeOne;
    double m_newValue;
    std::vector<double> m_vResults;
};

/**
 * Function calculates SQNR of to vectors of data
 *
 * SQNR is calculated as a mean squared error.
 * Error for each element is normalized by a
 */
double calcSqnr(const std::vector<double>& a, const std::vector<double>& b)
{
  if( a.size() != b.size() ) {
    std::cout << "Size mismatch" << std::endl;
    return 0.0;
  }
  double error = 0.0;
  for(unsigned int ii = 0; ii<a.size(); ++ii) {
    error += std::abs((a[ii]-b[ii])/a[ii]);
  }
  
  //looking for mean squared error
  error = error / a.size() ;

  return 10*log(error);
}

/**
 * Prints the prePend string and the contents of the vector
 */
template<typename T>
void printVector(const std::string prePend, const std::vector<T>& vec)
{
  for(typename std::vector<T>::const_iterator iter = vec.begin();
      iter != vec.end();
      ++iter)
  {
    std::cout << prePend << *iter << std::endl;
  }
}

/**
 * Code generates SQNR results for a generic Block class
 *
 * Code constructs two objects from one class,
 * one configured to be in fixed point and the other configured
 * as a floating point block. <br>
 * The fixed point is swept according to the initialBitWidth
 * and finalBitWidth unsigned int values by passing the
 * quant scheme into the constructor of the class. <br>
 * For each quant scheme numValues values are generated
 * using a [-1,1] boost::uniform distribution.
 * These values are passed to setters in the objects
 * and a SQNR results is collected for that quantization
 * scheme by calculating 10 * log10( (fixedPointResults -
 * floatingPointResults)^2 ). <br>
 * The SQNR for that value is push_back()d to the sqnrVector. <br>
 * This vector is then added to a map<unsigned int, std::vector<double> >
 * which holds the SQNR vector for each quant scheme. <br>
 * THe values are then printed out by traversing through the MAP.
 */
int main(int argc, char* argv[])
{
  unsigned int initialBitWidth = 1;
  unsigned int finalBitWidth = 16;
  unsigned int numValues = static_cast<unsigned int>(10);
  unsigned int numSamples = static_cast<unsigned int>(1e6);
  const int SEED = 42;
  boost::rand48 generator(SEED);
  boost::uniform_real<> distribution(-1,1);
  boost::variate_generator<boost::rand48&, boost::uniform_real<> > noiseGenerator(generator, distribution);
  
  std::cout << "Quant Scheme : ";
  std::map<unsigned int, std::vector<double> > sqnrMap;
  std::vector<double> vSqnr;
  vSqnr.reserve(numValues);
  
  for(unsigned int ii=initialBitWidth; ii <= finalBitWidth; ++ii) {
    bool isFixed = true;
    bool isNotFixed = false;
    Block blockA(isFixed, ii);
    Block blockB(isNotFixed);

    //clear SQNR vec for each bitWidth
    vSqnr.clear();

    for(unsigned int jj=0;jj<numValues;++jj){
      blockA.clearVector();
      blockB.clearVector();
      double newValue = noiseGenerator();
      blockA.setNewValue(newValue);
      blockB.setNewValue(newValue);
      for(unsigned int kk=0;kk<numSamples;++kk) {
        blockA.execute();
        blockB.execute();
      }
      double sqnr = calcSqnr( (blockA.getResults()), (blockB.getResults()) );
      vSqnr.push_back(sqnr);
      //std::cout << "For Value = " << newValue << " : SQNR = " << sqnr  << " dB" << std::endl;
    }
    
    //copy the sqnrVector for this value to the MAP
    sqnrMap[ii] = vSqnr;
  }

  for(unsigned int ii=initialBitWidth; ii <= finalBitWidth; ++ii) {
    std::cout << "Results for bitWidth = " << ii+1 << std::endl;
    std::cout <<  ii+1 << " totalBits, 1 integer bit (sign) :" << std::endl;
    ::printVector("SQNR = ", sqnrMap[ii]);
  }

}
