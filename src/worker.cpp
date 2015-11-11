#include <iostream>
#include "miner_maxer.h"
#include "vec.h"
#include "worker.h"
//------------------------------------------------------------------------------
int const Worker::INVALID_DISTANCE = -1;
//------------------------------------------------------------------------------
int Worker::safeDistanceSquared() {
  auto future = fSafeDistanceSquared.get_future();
  return future.get();
}
//------------------------------------------------------------------------------
void Worker::execute() {
  Maxer< int > maxDistance(INVALID_DISTANCE);

  if ( !fCfg.test().empty() ) {
    for (int x = fCfg.xBegin(), endX = fCfg.xEnd(); x <= endX; ++x) {
      auto const maxYZPlaneDistance = findMaxYZPlaneDistanceSquared(x);
      maxDistance.setValue(maxYZPlaneDistance);

      //std::cout << x << " of " << endX << std::endl;
    }
  }

  fSafeDistanceSquared.set_value( maxDistance.value() );
}
//------------------------------------------------------------------------------
int Worker::findMaxYZPlaneDistanceSquared(int const &aX) {
  Maxer< int > maxDistance(INVALID_DISTANCE);

  auto const sideSize = fCfg.sideSize();
  for (int y = 0; y <= sideSize; ++y) {
    for (int z = 0; z <= sideSize; ++z) {
      Point const point(aX, y, z);
      auto const minBombDistance = findMinBombDistanceSquared(point);
      maxDistance.setValue(minBombDistance);
    }
  }

  return maxDistance.value();
}
//------------------------------------------------------------------------------
int Worker::findMinBombDistanceSquared(Point const &aPoint) {
  auto const sideSize = fCfg.sideSize();
  Miner< int > minDistance(3 * sideSize  * sideSize);

  auto const test = fCfg.test();
  for (auto const &pointB : test) {
    Vec vector(aPoint, pointB);
    auto const bombDistance = vector.lengthSquared();
    minDistance.setValue( bombDistance );
  }

  return minDistance.value();
}
//------------------------------------------------------------------------------
