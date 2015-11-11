#ifndef WORKER_H__
#define WORKER_H__
//------------------------------------------------------------------------------
#include <future>
#include <memory>
#include "point.h"
#include "test.h"
//------------------------------------------------------------------------------
class WorkerCfg {
public:
  WorkerCfg() : fSideSize(0), fXBegin(0), fXEnd(0) {}

  int sideSize() const { return fSideSize; }
  void setSideSize(int const aVal) { fSideSize = aVal; }

  int xBegin() const { return fXBegin; }
  void setXBegin(int const aVal) { fXBegin = aVal; }

  int xEnd() const { return fXEnd; }
  void setXEnd(int const aVal) { fXEnd = aVal; }

  Test test() const { return fTest; }
  void setTest(Test const aVal) { fTest = aVal; }
private:
  int fSideSize;
  int fXBegin;
  int fXEnd;
  Test fTest;
};
//------------------------------------------------------------------------------
class Worker {
public:
  static int const INVALID_DISTANCE;
public:
  Worker(WorkerCfg const &aCfg) : fCfg(aCfg) {}

  void execute();

  int safeDistanceSquared();
private:
  int findMaxYZPlaneDistanceSquared(int const &aX);
  int findMinBombDistanceSquared(Point const &aPoint);
private:
  WorkerCfg fCfg;
  std::promise< int > fSafeDistanceSquared;
};
typedef std::shared_ptr< Worker > WorkerPtr;
//------------------------------------------------------------------------------
#endif
