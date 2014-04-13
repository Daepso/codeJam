#ifndef GCJ_PARSER_H__
#define GCJ_PARSER_H__

#include "CookieClicker.h"

#include <iostream>
#include <vector>

class Parser
{
  public:
    Parser();
    std::vector<CookieClicker> * load(const std::string& filename);

};

#endif

