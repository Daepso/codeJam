#include "Parser.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>


int main(int argc, char* argv[])
{
  if(argc <2)
  {
    std::cout << "Not enough arg" << std::endl;
    exit(1);
  }

  std::string fileName(argv[1]);
  int extOffset = fileName.find_last_of('.')+1;
  std::string outputFileName(fileName.substr(0,extOffset) + "out");
  std::cout << outputFileName << std::endl;

  std::ofstream file;
  file.open (outputFileName.c_str());

  Parser parser;
  std::vector<int> * answerdList = parser.load(argv[1]);
  std::cout << std::endl;
  std::cout << std::endl;
  for(unsigned int i=0; i<answerdList->size(); i++)
  {
    std::cout << (*answerdList)[i] << std::endl;
    if((*answerdList)[i] == -1)
    {
      file << "case #" << i+1 << ": Volunteer cheated!" << std::endl;; 
    }
    else if((*answerdList)[i] == 0)
    {
      file << "case #" << i+1 << ": Bad magician!" << std::endl;; 
    }
    else
    {
      file << "case #" << i+1 << ": " << (*answerdList)[i] << std::endl;; 
    }
  }
  file.close();
}
