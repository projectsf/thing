/**
 * Example illustrates use of MATLAB mex interface
 *
 * Goal is to create one routine that can be used for the
 * following situations:
 * <ul>
 * <li> Copying the contents of a MATLAB variable with name <variableName>
 * and type T into a std::vector<T>
 * The following types (T) need to be supported
 * <ul>
 * <li> double, complex<double> vector<complex<double> >
 * </ul>
 * </ul>
 *
 * @file matlabExternal.cpp
 */

#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include "mat.h"
#include <stdexcept>

/**
 * Splits a delimited std::string into a std::vector of std::strings
 *
 * Splits a delimited std::string into a std::vector of std::strings
 * delimited by the delimiter.
 *
 * @param inputString const reference of input string
 * @param delimiter delimiter used for split routine.  Defaults to "."
 * @return a vector of subStrings obtained by dividing input string by delimiter
 *
 */
std::vector<std::string> split(const std::string& inputString, const std::string& delimiter = ".")
{
  std::vector<std::string> vecOfString;

    //establish new and old positions
  unsigned int newPos = 0;
  unsigned int oldPos = 0;

    //break up inputString by delimiter
  while( (newPos = inputString.find(".", oldPos)) != std::string::npos)
  {
    unsigned int nameSize = newPos-oldPos;
    vecOfString.push_back(inputString.substr(oldPos, nameSize));
    oldPos = newPos + 1;
  }

    //capture either default string if no delimiters are present
    //or string after final delimiter
  vecOfString.push_back(inputString.substr(oldPos));

  return vecOfString;
    
}

struct PrintFunctor
{
  template<class T>
  void operator()(T in)
  {
    std::cout << in << std::endl;
  }

  template<class T>
  void operator()(std::vector<T> in)
  {
    for_each( in.begin(), in.end(), PrintFunctor() );
  }

};

class MatlabInterface
{
public:
  MatlabInterface()
    : m_pMatlabFile(NULL),
      m_pMxArray(NULL)
  {}
     
  void open(const std::string& fileName)
  {
    m_fileName = fileName;
    m_pMatlabFile = matOpen(m_fileName.c_str(), "r");
    if(!m_pMatlabFile)
      throw std::logic_error("Unable to open matlab file: " + fileName);
  }

  void close()
  {
    matClose(m_pMatlabFile);
  }

  template<typename T>
  void copy(const std::string& variableName, std::vector<T>& dataVec)
  {
    parseVariableName(variableName);
    getMxArray(variableName);
    copyFromMxArray(dataVec);
  }

    
private:
  MATFile *m_pMatlabFile;
  mxArray *m_pMxArray;
  std::string m_fileName;
  std::vector<std::string> m_hierarchicalNameVector;
  std::string m_matlabVariableName;
  std::vector<mxArray*> m_vecOfpMxArray;

  void parseVariableName(const std::string& variableName)
  {
    m_hierarchicalNameVector = ::split(variableName, ".");
    m_matlabVariableName = m_hierarchicalNameVector.at(0);
  }

  void getMxArray(const std::string& variableName)
  {
    if(m_hierarchicalNameVector.size() == 1) 
      m_pMxArray = matGetVariable(m_pMatlabFile,m_matlabVariableName.c_str());
    
    else {
      m_vecOfpMxArray.clear();
      //push back pMxArray pointer returned by getVariable call on to vector
      m_vecOfpMxArray.push_back(matGetVariable(m_pMatlabFile, m_matlabVariableName.c_str()));

      //iterator points to beginning of vector<mxArray*>
      std::vector<mxArray*>::iterator mxArrayIter = m_vecOfpMxArray.begin();

      //main vector creation loop
      for(std::vector<std::string>::iterator iter = m_hierarchicalNameVector.begin() + 1;
          iter != m_hierarchicalNameVector.end();
          ++iter, ++mxArrayIter)
      {
        // temp pointer to mxArray
        mxArray* pMxArrayTemp;
        const char* tempChar = (*iter).c_str();
        pMxArrayTemp=mxGetField(*mxArrayIter,0,tempChar);
        
        if( pMxArrayTemp )
        {
          m_vecOfpMxArray.push_back(pMxArrayTemp);
        }
      }

      m_pMxArray = *(m_vecOfpMxArray.end()-1);
    }
    
    if(!m_pMxArray)
      throw std::runtime_error("Can't find: " + variableName + ", in: " + m_fileName);
  }

  template<typename T>
  void copyFromMxArray(std::vector<T>& dataVec)
  {
    double *matlabData = static_cast<double*>(mxGetPr(m_pMxArray));
    int numberRows = mxGetM(m_pMxArray);

    dataVec.resize(numberRows);

    for(int row=0; row<numberRows; ++row) {
      dataVec[row] = (static_cast<T>(matlabData[row]));
    }
  }

  template<typename T>
  void copyFromMxArray(std::vector<std::complex<T> >& dataVec)
  {
    int numberRows = mxGetM(m_pMxArray);

    dataVec.resize(numberRows);

    double *pt_r = static_cast<double*>(mxGetPr(m_pMxArray));
    double *pt_i = static_cast<double*>(mxGetPi(m_pMxArray));
    const int *dims = mxGetDimensions(m_pMxArray);

    unsigned int col = 0;

    if(mxIsComplex(m_pMxArray))
      for(int row=0; row<dims[0]; ++row)
        dataVec[row] = (std::complex<T> (static_cast<T>(pt_r[row+col*dims[0]]), static_cast<T>(pt_i[row+col*dims[0]])));
    else
      for(int row=0; row<dims[0]; ++row)
        dataVec[row] = (std::complex<T> (static_cast<T>(pt_r[row+col*dims[0]]), 0));
  }

  template<typename T>
  void copyFromMxArray(std::vector<std::vector<T> >& dataVec)
  {
    double *matlabData = static_cast<double*>(mxGetPr(m_pMxArray));
    int numberColumns = mxGetN(m_pMxArray);
    int numberRows = mxGetM(m_pMxArray);

    std::vector<T> tempVec(numberRows);
    dataVec.resize(numberColumns);

    for(int col=0; col<numberColumns; ++col) {
      for(int row=0; row<numberRows; ++row) {
        int index = col * numberRows + row;
        tempVec[row] = (static_cast<T>(matlabData[index]));
      }
      dataVec[col] = tempVec;
    }
  }


};


int main()
{
  typedef std::vector<double> TpOneDimType;
  typedef std::vector<std::vector<double> > TpTwoDimType;
  TpOneDimType oneDimVec;
  TpTwoDimType twoDimVec;
  std::string fileName("./matlab/dump.mat");
  std::string oneDimName("oneDimStructure.oneDim");
  std::string twoDimName("twoDimStructure.twoDim");

  MatlabInterface myMat;
  myMat.open(fileName);

  try {
    myMat.copy(oneDimName,oneDimVec);
    myMat.copy(twoDimName,twoDimVec);
  }
  catch(std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
    throw;
  }

  //print out results
  std::cout << "One Dimensional results: " << std::endl;
  std::for_each( oneDimVec.begin(), oneDimVec.end(), PrintFunctor() );

  std::cout << "Two Dimensional results: " << std::endl;
  std::for_each( twoDimVec.begin(), twoDimVec.end(), PrintFunctor() );

  
}
