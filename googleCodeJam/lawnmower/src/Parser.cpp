#include "Parser.h"

#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

Parser::Parser()
{
}

std::vector<Lawn> * Parser::load(const std::string& filename)
{
  std::vector<Lawn> * lawnList =  new std::vector<Lawn>();
  std::ifstream file(filename.c_str());
  if(!file)
  {
    std::cerr << "Error: Cannot open file: " << filename << std::endl; 
    exit(1);
  }

  std::string line;
  getline(file, line);
  std::stringstream s(line);

  int testCaseNumber;
  s >> testCaseNumber;

  for(int i=0; i<testCaseNumber; i++)
  {
    int n,m;
    getline(file, line);
    std::stringstream s(line);
    s >> n;
    s >> m;
    Lawn lawn(n,m);
    for(int j=0; j<n; j++)
    {
      getline(file, line);
      std::stringstream s(line);
      for(int k=0; k<m; k++)
      {
        int height;
        s >> height;
        lawn.set(j,k,height);
      }
    }
    lawnList->push_back(lawn);
  }
  return lawnList;
}

