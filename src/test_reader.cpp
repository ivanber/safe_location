#include <fstream>
#include <iostream>
#include "test_parser.h"
#include "test_reader.h"
//------------------------------------------------------------------------------
bool TestReader::read(std::string const &aFileName, TestReader::Tests &aTests) {
  bool success = false;

  std::ifstream ifl(aFileName, std::ios_base::in);
  if (ifl) {
    success = true;

    enum Step {STEP_NUM_TESTS, STEP_NUM_POINTS, STEP_POINT, STEP_END};

    int t = 0;
    int n = 0;
    Point p;
    Test test;
    int step = STEP_NUM_TESTS;
    while (STEP_END != step) {
      switch (step) {
      case STEP_NUM_TESTS:
        if ( NumParser::parse(ifl, t) ) {
          step = STEP_NUM_POINTS;
        } else {
          step = STEP_END;
        }
        break;
      case STEP_NUM_POINTS:
        test.clear();

        if ( NumParser::parse(ifl, n) ) {
          step = STEP_POINT;
        } else {
          step = STEP_END;
        }
        break;
      case STEP_POINT:
        if ( PointParser::parse(ifl, p) ) {
          test.push_back(p);

          if (0 >= --n) {
            aTests.push_back(test);

            if (0 >= --t) {
              step = STEP_END;
            } else {
              step = STEP_NUM_POINTS;
            }
          }
        }
        break;
      }
    }
  } else {
    std::cerr << "Fault open input file " << aFileName << std::endl;
  }

  return success;
}
//------------------------------------------------------------------------------
