#include "Parser.h"
#include "CookieClicker.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>
#include <iomanip>

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
  std::vector<CookieClicker> * ccList = parser.load(argv[1]);
  std::cout << std::fixed << std::setprecision(7);
  file << std::fixed << std::setprecision(7);
  for(unsigned int i=0; i<ccList->size(); i++)
  {
    double time = (*ccList)[i].solve();
    std::cout << time << std::endl;
    file << "case #" << i+1 << ": " << time << std::endl;; 
  }
  file.close();
  return 0;
}
