#include <cstdlib>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>

std::vector<std::list<int> > tripletList; 

void loadFile(char * fileName)
{
  std::ifstream file(fileName);
  if(!file)
  {
    std::cerr << "Error: Cannot open file: " << fileName << std::endl; 
    exit(1);
  }

  std::string line;
  getline(file, line);

  while(!file.eof())
  {
    std::stringstream s(line);

    int nb;
    s >> nb;
    std::list<int> triplet;
    triplet.push_back(nb/100);
    nb -= (nb/100)*100;
    triplet.push_back(nb/10);
    nb -= (nb/10)*10;
    triplet.push_back(nb);
    tripletList.push_back(triplet);
    getline(file, line);
  }
}

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cerr << "Error: not enough" << std::endl;
  }

  loadFile(argv[1]);

  for(unsigned int i=0; i<tripletList.size(); i++)
  {
    for(std::list<int>::iterator it=tripletList[i].begin(); it != tripletList[i].end(); ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
}
