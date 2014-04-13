#include "Parser.h"

#include <cstdlib>
#include <fstream>
#include <istream>
#include <sstream>

Parser::Parser()
{
}

std::vector<CookieClicker> * Parser::load(const std::string& filename)
{
  std::vector<CookieClicker> * ccList =  new std::vector<CookieClicker>();
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
    double c,f,x;
    getline(file, line);
    std::stringstream s(line);
    s >> c;
    s >> f;
    s >> x;
    CookieClicker cc(c,f,x);
    ccList->push_back(cc);
  }
  return ccList;
}

