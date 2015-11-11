#ifndef VEC_H__
#define VEC_H__
//------------------------------------------------------------------------------
#include "point.h"
//------------------------------------------------------------------------------
class Vec : public Point {
public:
  Vec(Point const &aPointA, Point const &aPointB);

  int lengthSquared() const;
};
//------------------------------------------------------------------------------
#endif
