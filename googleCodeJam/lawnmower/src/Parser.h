#ifndef GCJ_PARSER_H__
#define GCJ_PARSER_H__

#include "Lawn.h"

#include <iostream>
#include <vector>

class Parser
{
  public:
    Parser();
    std::vector<Lawn> * load(const std::string& filename);

};

#endif

