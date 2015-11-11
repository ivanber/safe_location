#include "vec.h"
#include <math.h>
//------------------------------------------------------------------------------
Vec::Vec(Point const &aPointA, Point const &aPointB)
  : Point(
    aPointB.x() - aPointA.x(),
    aPointB.y() - aPointA.y(),
    aPointB.z() - aPointA.z()
  ) {}
//------------------------------------------------------------------------------
int Vec::lengthSquared() const {
  auto const coordX = x();
  auto const coordY = y();
  auto const coordZ = z();

  auto const lenSquared = coordX * coordX + coordY * coordY + coordZ * coordZ;
  return lenSquared;
}
//------------------------------------------------------------------------------
