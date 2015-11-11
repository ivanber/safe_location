#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "worker.h"
//------------------------------------------------------------------------------
TEST_CASE("valid", "check valid input") {
  WorkerCfg workerCfg;
  workerCfg.setSideSize(10);
  workerCfg.setXBegin(0);
  workerCfg.setXEnd(10);

  Test test;
  test.push_back( Point(0, 10, 10) );
  test.push_back( Point(0, 0, 10) );
  workerCfg.setTest(test);

  Worker worker(workerCfg);
  worker.execute();

  auto const distance = worker.safeDistanceSquared();
  REQUIRE_FALSE(distance == Worker::INVALID_DISTANCE);

  REQUIRE(distance == 225);
}
//------------------------------------------------------------------------------
TEST_CASE("invalid_beg_end", "check invalid input beg end") {
  WorkerCfg workerCfg;
  workerCfg.setSideSize(10);
  workerCfg.setXBegin(10);
  workerCfg.setXEnd(0);

  Test test;
  test.push_back( Point(0, 10, 10) );
  test.push_back( Point(0, 0, 10) );
  workerCfg.setTest(test);

  Worker worker(workerCfg);
  worker.execute();

  auto const distance = worker.safeDistanceSquared();
  REQUIRE(distance == Worker::INVALID_DISTANCE);
}
//------------------------------------------------------------------------------
TEST_CASE("invalid_test", "check invalid input test") {
  WorkerCfg workerCfg;
  workerCfg.setSideSize(10);
  workerCfg.setXBegin(0);
  workerCfg.setXEnd(10);

  Test test;
  workerCfg.setTest(test);

  Worker worker(workerCfg);
  worker.execute();

  auto const distance = worker.safeDistanceSquared();
  REQUIRE(distance == Worker::INVALID_DISTANCE);
}
//------------------------------------------------------------------------------
TEST_CASE("invalid_side_size", "check invalid input side size") {
  WorkerCfg workerCfg;
  workerCfg.setSideSize(-10);
  workerCfg.setXBegin(0);
  workerCfg.setXEnd(10);

  Test test;
  test.push_back( Point(0, 10, 10) );
  test.push_back( Point(0, 0, 10) );
  workerCfg.setTest(test);

  Worker worker(workerCfg);
  worker.execute();

  auto const distance = worker.safeDistanceSquared();
  REQUIRE(distance == Worker::INVALID_DISTANCE);
}
//------------------------------------------------------------------------------
