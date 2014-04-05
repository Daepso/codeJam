#include "Lawn.h"
#include "Parser.h"

#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>


int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Argument missing!" << std::endl;
    return 1;
  }
  else
  {
    std::string fileName(argv[1]);
    int extOffset = fileName.find_last_of('.')+1;
    std::string outputFileName(fileName.substr(0,extOffset) + "out");
    std::cout << outputFileName << std::endl;

    std::ofstream file;
    file.open (outputFileName.c_str());
    Parser parser;
    std::vector<Lawn> & lawnList = *parser.load(argv[1]);
    for(int i=0; i<lawnList.size(); i++)
    {
      lawnList[i].display();
      if(lawnList[i].isPossible())
      {
        std::cout << "true" << std::endl;
        file << "Case #" << i+1 << ": YES" << std::endl;; 
      }
      else
      {
        std::cout << "false" << std::endl;
        file << "Case #" << i+1 << ": NO" << std::endl;; 
      }
      std::cout << std::endl;
    }
    file.close();
    return 0;
  }
}
