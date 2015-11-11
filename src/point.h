#ifndef POINT_H__
#define POINT_H__
//------------------------------------------------------------------------------
class Point {
public:
  Point() : fX(0), fY(0), fZ(0) {}
  Point(int const &aX, int const &aY, int const &aZ) : fX(aX), fY(aY), fZ(aZ) {}
  virtual ~Point() {}

  int x() const { return fX; }
  void setX(int const &aVal) { fX = aVal; }

  int y() const { return fY; }
  void setY(int const &aVal) { fY = aVal; }

  int z() const { return fZ; }
  void setZ(int const &aVal) { fZ = aVal; }
private:
  int fX;
  int fY;
  int fZ;
};
//------------------------------------------------------------------------------
#endif
