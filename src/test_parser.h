#ifndef TEST_PARSER_H__
#define TEST_PARSER_H__
//------------------------------------------------------------------------------
#include <iostream>
#include "point.h"
//------------------------------------------------------------------------------
class NumParser {
public:
  static bool parse(std::istream &aStream, int &aNum);
};
//------------------------------------------------------------------------------
class PointParser {
public:
  static bool parse(std::istream &aStream, Point &aPoint);
};
//------------------------------------------------------------------------------
#endif
