
#include <systemc>
#include <math.h>
#include <vector>


double calcSnr(std::vector<double>& a, std::vector<double>& b)
{
  if(a.size() != b.size())
    std::cout << "Size mismatch" << std::endl;
  double error = 0.0;
  for(unsigned int ii = 0; ii<a.size(); ++ii)
    error += pow(a[ii],2) - pow(b[ii],2);

  return 20*log(error);
}

using namespace sc_dt;


int sc_main(int argc, char *argv[])
{
  if (argc != 4) {
    std::cout << "Usage: " << std::endl;
    std::cerr << "$ run.x desiredFreq samplingFreq numSteps" << std::endl;
    std::cerr << "Error: " << argc << " is not the correct number of arguments" << std::endl;
    return false;
  }

  //sc_fxcast_switch fcs(SC_OFF);
  //sc_fxcast_context fcscx(fcs);

  int desiredFreq = atoi(argv[1]);
  int samplingFreq = atoi(argv[2]);
  int numSteps = atoi(argv[3]);
  double freqRatio = static_cast<double>(desiredFreq)/static_cast<double>(samplingFreq);
  std::vector<double> fixedValues(numSteps);
  std::vector<double> floatValues(numSteps);


  {
    sc_fixed<20,1> freqWord;
    sc_fixed<18,1,SC_TRN,SC_WRAP> accumOutput = 0;
    sc_fixed<12,1,SC_TRN,SC_WRAP> accumOutputTrunc;
    sc_fixed<12,1,SC_TRN,SC_WRAP> firstRotationValue = 0.125;
    sc_fixed<12,1,SC_TRN,SC_WRAP> firstRotateOutput;
    sc_ufixed<12,2,SC_TRN> firstRotateOutputTemp;
    sc_ufixed<2,2,SC_TRN> twoMsbs;
    sc_fixed<10,-1,SC_TRN, SC_WRAP> firstRotateShiftedByTwo;
    sc_fixed<10,-1,SC_TRN,SC_WRAP> secondRotationValue = 0.125;
    sc_fixed<10,-1,SC_TRN,SC_WRAP> secondRotateOutput;
  
    for(int ii=0;ii<numSteps;++ii) {
      freqWord = freqRatio;
      accumOutput = accumOutput + freqWord;
  
      //truncate accum output
      accumOutputTrunc = accumOutput;
  
      //first rotate
      firstRotateOutput = accumOutputTrunc + firstRotationValue;
  
      //extract two msbs
      twoMsbs = firstRotateOutput << 2;
    
      //grab lower msbs
      firstRotateShiftedByTwo = firstRotateOutput;
  
      //final rotate
      secondRotateOutput = firstRotateShiftedByTwo + secondRotationValue;
  
      fixedValues.push_back(secondRotateOutput);
      std::cout << "---------Fixed-------------" << std::endl;
      std::cout << "Two MSBS: " << twoMsbs.to_string() << std::endl;
      std::cout << "The rest: " << secondRotateOutput.to_string() << std::endl;
    }
  }

  {
    sc_fixed<20,1> freqWord;
    sc_fixed<18,1,SC_TRN,SC_WRAP> accumOutput = 0;
    sc_fixed<12,1,SC_TRN,SC_WRAP> accumOutputTrunc;
    sc_fixed<12,1,SC_TRN,SC_WRAP> firstRotationValue = 0.125;
    sc_fixed<12,1,SC_TRN,SC_WRAP> firstRotateOutput;
    sc_ufixed<12,2,SC_TRN> firstRotateOutputTemp;
    sc_ufixed<2,2,SC_TRN> twoMsbs;
    sc_fixed<10,-1,SC_TRN, SC_WRAP> firstRotateShiftedByTwo;
    sc_fixed<10,-1,SC_TRN,SC_WRAP> secondRotationValue = 0.125;
    sc_fixed<10,-1,SC_TRN,SC_WRAP> secondRotateOutput;
    
  
    //reset accumulator
    accumOutput = 0;
    for(int ii=0;ii<numSteps;++ii) {
  
      sc_fxcast_switch fcs(SC_OFF);
      sc_fxcast_context fcscx(fcs);
  
      freqWord = freqRatio;
      
      accumOutput = accumOutput + freqWord;
  
      //truncate accum output
      accumOutputTrunc = accumOutput;
  
      //first rotate
      firstRotateOutput = accumOutputTrunc + firstRotationValue;
  
      //extract two msbs
      twoMsbs = firstRotateOutput << 2;
    
      //grab lower msbs
      firstRotateShiftedByTwo = firstRotateOutput;
  
      //final rotate
      secondRotateOutput = firstRotateShiftedByTwo + secondRotationValue;
  
      floatValues.push_back(secondRotateOutput);
      std::cout << "---------Float-----------" << std::endl;
      std::cout << "Two =MSBS: " << twoMsbs.to_string() << std::endl;
      std::cout << "The rest: " << secondRotateOutput.to_string() << std::endl;
    }
  }

  std::cout << "Sqnr = " << calcSnr(floatValues,fixedValues) << std::endl;

  return 1;

}
 