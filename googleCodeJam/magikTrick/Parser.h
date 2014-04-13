#ifndef GCJ_PARSER_H__
#define GCJ_PARSER_H__

#include <iostream>
#include <vector>

class Parser
{
  public:
    Parser();
    std::vector<int> * load(const std::string& filename);

};

#endif

