/**
 * Example uses boost's file system library to traverse a directory
 *
 * @file boostFileSystemExample.cpp
 */

//new
#include <string>
#include "utilities/stringUtilities.h"
#include "utilities/matUtilities.hpp"
//end of new
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
#include <stdexcept>


// *******************************************************
// Searches the interop file directory for interop files 
// and returns their names in a vector or strings.
// *******************************************************

std::vector<std::string> getMatlabInteropFiles()
{
  std::string file;
  unsigned int file_count = 0;

  // Create interop filename vector
  boost::filesystem::path interopPath("/vobs/sv_system_modeling/uwbModel/interop_test_vectors/");
  //boost::filesystem::path interopPath("/home/a0871095/cppTemp");
  std::vector<std::string> interopMatlabFile;
  interopMatlabFile.reserve(40);

  if(!boost::filesystem::exists(interopPath))
  {
    std::string errorMessage= interopPath.native_file_string() + " not found." + "\n";
    std::cerr << interopPath.native_file_string() << " not found." << std::endl;
    throw std::runtime_error(errorMessage);
  }

  boost::filesystem::directory_iterator end_itr;
  for(boost::filesystem::directory_iterator itrOuter(interopPath); itrOuter != end_itr; ++itrOuter)
  {


    // don't want to handle burst mode yet, so we skip it here
    if(boost::filesystem::is_directory(*itrOuter) && ((itrOuter->leaf()).find("burst") == std::string::npos))
    {
      boost::filesystem::path newPath = boost::filesystem::complete(itrOuter->leaf(), interopPath);
      for(boost::filesystem::directory_iterator itrInner(newPath); itrInner != end_itr; ++itrInner)
      {
        // Ignore the zero length 53 case
        if(!boost::filesystem::is_directory(*itrInner) && ((itrInner->leaf()).find("53_0") == std::string::npos))
        {
          ++file_count;
          boost::filesystem::path fullPath = boost::filesystem::complete(itrInner->leaf(), newPath);
          interopMatlabFile.push_back(fullPath.native_file_string());
        }
      }
    }
  }

  return interopMatlabFile;

}


void openAndCloseFiles(std::vector<std::string> inVec)
{
  std::ifstream inFile;
  //open and close  each file in vector
  for(std::vector<std::string>::iterator iter = inVec.begin();
      iter!= inVec.end();
      ++iter)
  {
    //std::cout << "Found: " <<  *iter  << std::endl;
    std::cout << "load " <<  *iter  << std::endl;
    inFile.open( (*iter).c_str() );

    //report error if file can't be opened
    if(!inFile)
    {
      std::string errorMessage= "Can't open: " + *iter + "\n";
      throw std::runtime_error(errorMessage);
    }
    inFile.close();
  }

  std::cout << "****************************************" << std::endl;
  std::cout << "* All files were successfully accessed *" << std::endl;
  std::cout << "****************************************" << std::endl;

  
}

int main()
{
  try
  {
    std::vector<std::string> myVec = getMatlabInteropFiles();
    openAndCloseFiles(myVec);
  }
  catch(std::exception exc)
  {
    std::cout << "Caught exception in file parsing routine" << std::endl;
    std::cout << "File System not properly mounted or visible" << std::endl;
    std::cout << "Exception is : " << exc.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Caught exception in file parsing routine" << std::endl;
  }

}
