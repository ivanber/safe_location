#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "miner_maxer.h"
//------------------------------------------------------------------------------
TEST_CASE("miner/init", "check init value") {
  Miner< int > miner(500);

  REQUIRE( 500 == miner.value() );
}
//------------------------------------------------------------------------------
TEST_CASE("miner/valid", "check valid") {
  Miner< int > miner(100);

  miner.setValue(10);
  miner.setValue(-10);
  miner.setValue(50);
  miner.setValue(0);
  miner.setValue(20);

  REQUIRE( -10 == miner.value() );
}
//------------------------------------------------------------------------------
TEST_CASE("maxer/init", "check init value") {
  Miner< int > miner(-500);

  REQUIRE( -500 == miner.value() );
}
//------------------------------------------------------------------------------
TEST_CASE("maxer/valid", "check valid") {
  Maxer< int > maxer(-100);

  maxer.setValue(10);
  maxer.setValue(-10);
  maxer.setValue(50);
  maxer.setValue(0);
  maxer.setValue(20);

  REQUIRE( 50 == maxer.value() );
}
//------------------------------------------------------------------------------
