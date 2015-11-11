#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "test_reader.h"
//------------------------------------------------------------------------------
TEST_CASE("single_test_single_points", "read file with one test and one point")
{
  TestReader::Tests tests;
  REQUIRE( true == TestReader::read("single_test_single_point.txt", tests) );

  REQUIRE( 1 == tests.size() );

  auto const points = tests[0];
  REQUIRE( 1 == points.size() );

  auto const point = points[0];
  REQUIRE( 0 == point.x() );
  REQUIRE( -500 == point.y() );
  REQUIRE( 1000 == point.z() );
}
//------------------------------------------------------------------------------
TEST_CASE("single_test_multiple_points",
  "read file with one test and many points")
{
  TestReader::Tests tests;
  REQUIRE( true == TestReader::read("single_test_multiple_points.txt", tests) );

  REQUIRE( 1 == tests.size() );

  auto const points = tests[0];
  REQUIRE( 5 == points.size() );

  Point checkPoints[] = {
    Point(100, 200, 300),
    Point(500, 600, 200),
    Point(3, 50, 430),
    Point(80, 57, 499),
    Point(1555, 4667, 2344)
  };
  for (size_t i = 0, n = points.size(); i < n; ++i) {
    auto const point = points[i];
    auto const checkPoint = checkPoints[i];

    REQUIRE( point.x() == checkPoint.x() );
    REQUIRE( point.y() == checkPoint.y() );
    REQUIRE( point.z() == checkPoint.z() );
  }
}
//------------------------------------------------------------------------------
TEST_CASE("multiple_tests", "read file with multiple tests") {
  TestReader::Tests tests;
  REQUIRE( true == TestReader::read("multiple_tests.txt", tests) );

  REQUIRE( 3 == tests.size() );

  Point test1[] = {
    Point(1, 2, 3),
    Point(-1, -2, -3)
  };

  Point test2[] = {
    Point(123, 4567, 993),
    Point(456, 925, -25),
    Point(0, 234, 6626),
    Point(5563, 6726, 442)
  };

  Point test3[] = {
    Point(22, 4, 567)
  };

  Test checkTests[] = {
    Test( std::begin(test1), std::end(test1) ),
    Test( std::begin(test2), std::end(test2) ),
    Test( std::begin(test3), std::end(test3) )
  };

  for (size_t i = 0, n = tests.size(); i < n; ++i) {
    auto const points = tests[i];
    auto const checkPoints = checkTests[i];

    REQUIRE( points.size() == checkPoints.size() );

    for (size_t j = 0, m = points.size(); j < m; ++j) {
      auto const point = points[j];
      auto const checkPoint = checkPoints[j];

      REQUIRE( point.x() == checkPoint.x() );
      REQUIRE( point.y() == checkPoint.y() );
      REQUIRE( point.z() == checkPoint.z() );
    }
  }
}
//------------------------------------------------------------------------------
TEST_CASE("file_not_exists", "check if file not exists") {
  TestReader::Tests tests;
  REQUIRE( false == TestReader::read("not_existings_file", tests) );
}
//------------------------------------------------------------------------------
