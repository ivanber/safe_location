#ifndef TEST_READER_H__
#define TEST_READER_H__
//------------------------------------------------------------------------------
#include <string>
#include "test.h"
//------------------------------------------------------------------------------
class TestReader {
public:
  typedef std::vector< Test> Tests;
public:
  static bool read(std::string const &aFileName, Tests &aTests);
};
//------------------------------------------------------------------------------
#endif
