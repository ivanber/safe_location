#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "vec.h"
//------------------------------------------------------------------------------
TEST_CASE("vec_coord", "check vector coordinates") {
  struct CoordCheck {
    Point a;
    Point b;
    int x;
    int y;
    int z;
  };

  CoordCheck coordChecks[] = {
    { {-1, 100, 34}, {50, -200, -30}, 51, -300, -64},
    { {1, 1, 1}, {1, 1, 1}, 0, 0, 0},
    { {-1, -1, -1}, {1, 1, 1}, 2, 2, 2},
    { {1, 1, 1}, {-1, -1, -1}, -2, -2,- 2}
  };

  for (auto const &coordCheck : coordChecks) {
    Vec ab(coordCheck.a, coordCheck.b);

    REQUIRE(ab.x() == coordCheck.x);
    REQUIRE(ab.y() == coordCheck.y);
    REQUIRE(ab.z() == coordCheck.z);
  }
}
//------------------------------------------------------------------------------
TEST_CASE("vec_length", "check calculate vector length") {
  struct LengthCheck{
    Point a;
    Point b;
    int length;
  };
  LengthCheck lengthChecks[] = {
    { {0, 0, 0}, {0, 1, 0}, 1 },
    { {1, 0, 0}, {0, 0, 0}, 1 },
    { {0, 0, 0}, {0, 0, 1}, 1 },
    { {0, 0, 0}, {0, 0, 0}, 0 },
    { {2, -1, 0}, {0, 1, 1}, 9 }
  };

  for (auto const &lengthCheck : lengthChecks) {
    Vec ab(lengthCheck.a, lengthCheck.b);
    auto const length = ab.lengthSquared();

    REQUIRE(lengthCheck.length == length);
  }
}
//------------------------------------------------------------------------------
