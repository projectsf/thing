/**
 * Example illustrates how to use
 * sc_fix type
 *
 * @file fixedPoint_sc_main.cpp
 */

#include <systemc>
using namespace sc_dt;


/**
 * main block
 *
 * Arguments:
 * <ul>
 * <li> isSigned (1 | 0)
 * <li> input_wl (positive integer, non-zero)
 * <li> input_iwl (signed integer)
 * <li> output_wl (positive integer, non-zero)
 * <li> output_iwl (signed integer)
 * <li> sc_o_mode (0 to 4)
 * <li> sc_q_mode (0 to 6)
 */

int sc_main(int argc, char *argv[])
{
  if (argc != 8) {
    std::cout << "Usage: " << std::endl;
    std::cerr << "$ run.x isSigned input_wl input_iwl output_wl output_iwl -sc_q_mode -sc_o_mode" << std::endl;
    std::cerr << "Error: " << argc << " is not the correct number of arguments" << std::endl;
    return false;
  }

  else {
  
    //capture arguments
    int isSigned = atoi(argv[1]);
    int input_wl = atoi(argv[2]);
    int input_iwl = atoi(argv[3]);
    int output_wl = atoi(argv[4]);
    int output_iwl = atoi(argv[5]);
    sc_dt::sc_q_mode q_mode;
    switch ( atoi(argv[6]) ) {
      case 0 : {
        q_mode = SC_RND;
        break;
      }
      case 1 : {
        q_mode = SC_RND_ZERO;
        break;
      }
      case 2 : {
        q_mode = SC_RND_MIN_INF;
        break;
      }
      case 3 : {
        q_mode = SC_RND_INF;
        break;
      }
      case 4 : {
        q_mode = SC_RND_CONV;
        break;
      }
      case 5 : {
        q_mode = SC_TRN;
        break;
      }
      case 6 : {
        q_mode = SC_TRN_ZERO;
        break;
      }
      default :
        break;
    }
    
    sc_dt::sc_o_mode o_mode;
    switch ( atoi(argv[7]) ) {
      case 0 : {
        o_mode = SC_SAT;
        break;
      }
      case 1 : {
        o_mode = SC_SAT_ZERO;
        break;
      }
      case 2 : {
        o_mode = SC_SAT_SYM;
        break;
      }
      case 3 : {
        o_mode = SC_WRAP;
        break;
      }
      case 4 : {
        o_mode = SC_WRAP_SM;
        break;
      }
      default :
        break;
    }
  
  
    //generate stimulus
    double maxValue;
    double minValue;
    double stepSize;
    if(isSigned) {
      minValue = -1 * pow(2, input_iwl - 1);
      maxValue = pow(2, input_iwl - 1) - pow(2, -1*(input_wl-input_iwl));
      stepSize = pow(2, input_iwl - input_wl);
    }
    else {
      minValue = 0;
      maxValue = pow(2, input_iwl) - pow(2, -1*(input_wl - input_iwl));
      stepSize = pow(2, input_iwl - input_wl);
    }

  
    //configure sc_fxtype context with config read in from command line
    sc_fxtype_params outFxParams(output_wl, output_iwl, q_mode, o_mode);
    sc_fxtype_context outFxContext(outFxParams);

    sc_fix signedOutput;
    sc_ufix unsignedOutput;

  
  
    std::cout << "inputValue\t" << "outputValue\t" << std::endl;
    std::cout << "stepSize = " << stepSize << std::endl;
    for(double ii = minValue; ii <= maxValue; ii+=stepSize)
    {
      if(isSigned) {
        signedOutput = ii;
        std::cout << ii << "\t" << signedOutput << "\t" << signedOutput.to_string(SC_BIN) << std::endl;
      }
      else {
        unsignedOutput = ii;
        std::cout << ii << "\t" << unsignedOutput << "\t" << unsignedOutput.to_string(SC_BIN) << std::endl;
        //std::cout << ii << "\t" << unsignedOutput.to_string(SC_BIN) << std::endl;
      }
        
    }
  
    return true;
  }

}
