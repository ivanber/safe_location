#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "test_parser.h"
//------------------------------------------------------------------------------
TEST_CASE("num_parser/correct_value", "check parse correct value") {
  int const checkValues[] = {12, 54, -124, 0, 465673};

  for (auto const &checkValue : checkValues) {
    std::stringstream ss;
    ss << checkValue << std::endl;

    int out = 0;
    NumParser::parse(ss, out);

    REQUIRE(checkValue == out);
  }
}
//------------------------------------------------------------------------------
TEST_CASE("num_parser/correct_value_wo_endl", "check parse correct value"
  "without endl")
{
  int const checkValues[] = {-500, 243, -1, 15, 32735};

  for (auto const &checkValue : checkValues) {
    std::stringstream ss;
    ss << checkValue;

    int out = 0;
    REQUIRE( true == NumParser::parse(ss, out) );

    REQUIRE(checkValue == out);
  }
}
//------------------------------------------------------------------------------
TEST_CASE("num_parser/incorrect_value", "check parse incorrect value") {
  std::string const checkValues[] = {"wqeqrw", "99999999999999999999999999999",
    "werwer234234234"};

  for (auto const &checkValue : checkValues) {
    std::stringstream ss;
    ss << checkValue;

    int out = 0;
    REQUIRE( false == NumParser::parse(ss, out) );
  }
}
//------------------------------------------------------------------------------
TEST_CASE("point_parser/correct_value", "check parse correct value") {
  struct CheckValue {
    std::string in;
    int x;
    int y;
    int z;
  };

  CheckValue const checkValues[] = {
    {"500 1000 -123", 500, 1000, -123},
    {"0 12 -15", 0, 12, -15},
    {"0 0 0", 0, 0, 0}
  };

  for (auto const &checkValue : checkValues) {
    std::stringstream ss;
    ss << checkValue.in;

    Point out;
    REQUIRE( true == PointParser::parse(ss, out) );

    REQUIRE( checkValue.x == out.x() );
    REQUIRE( checkValue.y == out.y() );
    REQUIRE( checkValue.z == out.z() );
  }
}
//------------------------------------------------------------------------------
TEST_CASE("point_parser/incorrect_value", "check parse incorrect value") {
  struct CheckValue {
    std::string in;
    int x;
    int y;
    int z;
  };

  std::string const checkValues[] = {"500 f1000 -123",
    "-9999999999999999999999 12 -15", ""};
  for (auto const &checkValue : checkValues) {
    std::stringstream ss;
    ss << checkValue;

    Point out;
    REQUIRE( false == PointParser::parse(ss, out) );
  }
}
//------------------------------------------------------------------------------
