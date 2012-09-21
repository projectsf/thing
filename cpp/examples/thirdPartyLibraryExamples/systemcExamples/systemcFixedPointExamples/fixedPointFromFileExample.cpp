/**
 * Example illustrates how to use
 * sc_fix type
 *
 * @file fixedPointFromFileExample.cpp
 */

#include <systemc>
#include <map>
using namespace sc_dt;

class FxPointContext
{
public:
  FxPointContext()
    : m_contextName("A context"),
      m_isSigned(1),
      m_wl(7),
      m_iwl(7),
      m_q_mode(SC_RND),
      m_o_mode(SC_SAT)
  {
  }

  std::string getContextName() const
  {
    return m_contextName;
  }

  void setIsSigned(int in)
  {
    m_isSigned = in;
  }

  void setWl(int in)
  {
    m_wl = in;
  }

  int getWl() const
  {
    return m_wl;
  }

  void setIwl(int in)
  {
    m_iwl = in;
  }

  int getIwl() const
  {
    return m_iwl;
  }

  void setQmode(int in)
  {
    switch ( in ) {
      case 0 : {
        m_q_mode = SC_RND;
        break;
      }
      case 1 : {
        m_q_mode = SC_RND_ZERO;
        break;
      }
      case 2 : {
        m_q_mode = SC_RND_MIN_INF;
        break;
      }
      case 3 : {
        m_q_mode = SC_RND_INF;
        break;
      }
      case 4 : {
        m_q_mode = SC_RND_CONV;
        break;
      }
      case 5 : {
        m_q_mode = SC_TRN;
        break;
      }
      case 6 : {
        m_q_mode = SC_TRN_ZERO;
        break;
      }
      default :
        break;
    }
  }

  sc_dt::sc_q_mode getQmode() const
  {
    return m_q_mode;
  }

  void setOmode(int in)
  {
    switch ( in ) {
      case 0 : {
        m_o_mode = SC_SAT;
        break;
      }
      case 1 : {
        m_o_mode = SC_SAT_ZERO;
        break;
      }
      case 2 : {
        m_o_mode = SC_SAT_SYM;
        break;
      }
      case 3 : {
        m_o_mode = SC_WRAP;
        break;
      }
      case 4 : {
        m_o_mode = SC_WRAP_SM;
        break;
      }
      default :
        break;
    }
  }

  sc_dt::sc_o_mode getOmode() const
  {
    return m_o_mode;
  }


  bool operator<(const FxPointContext& rhs)
  {
    return m_contextName < rhs.getContextName();
  }
    
private:
  std::string m_contextName;
  int m_isSigned;
  int m_wl;
  int m_iwl;
  sc_dt::sc_q_mode m_q_mode; //0 = sc_rnd
  sc_dt::sc_o_mode m_o_mode; //0 = sc_sat

};


class Accumulator
{
public:
  
  Accumulator(std::map<std::string, FxPointContext>& fxContextMap)
    : accumInput(sc_fxtype_params(
               fxContextMap["accumInput"].getWl(),
               fxContextMap["accumInput"].getIwl(),
               fxContextMap["accumInput"].getQmode(),
               fxContextMap["accumInput"].getOmode() ) ),
      accumOutput(sc_fxtype_params(
                fxContextMap["accumOutput"].getWl(),
                fxContextMap["accumOutput"].getIwl(),
                fxContextMap["accumOutput"].getQmode(),
                fxContextMap["accumOutput"].getOmode() ) )

  {
    accumInput = 1;
    accumOutput = 0;
  }

  void execute()
  {
    for(unsigned int ii=0; ii<100; ++ii) {
      accumOutput = accumInput + accumOutput;
    }
  }

  std::string getAccumOutput() const
  {
    return accumOutput.to_string();
  }

private:
  sc_fix accumInput;
  sc_fix accumOutput;
};


/**
 * main block
 *
 */

int sc_main(int argc, char *argv[])
{
  //read in all contexts into vector for accumulator block
  std::map<std::string, FxPointContext> fxContextMap;

  
  FxPointContext fxOne;
  fxContextMap["accumInput"] = fxOne;

  FxPointContext fxTwo;
  fxTwo.setWl(24);
  fxTwo.setIwl(16);
  fxContextMap["accumOutput"] = fxTwo;

  //instantiate Accumulator with fx point contexts
  Accumulator accum(fxContextMap);
  accum.execute();
  std::cout << accum.getAccumOutput() << std::endl;

  return 1;

}
