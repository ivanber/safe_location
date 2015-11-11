#define CATCH_CONFIG_MAIN
//------------------------------------------------------------------------------
#include <catch.hpp>
#include "ranker.h"
//------------------------------------------------------------------------------
TEST_CASE("valid_1", "check valid") {
  RankerCfg rankerCfg;
  rankerCfg.setBegin(0);
  rankerCfg.setEnd(20);
  rankerCfg.setCount(4);

  auto const ranks = Ranker::doRank(rankerCfg);
  REQUIRE( 4 == ranks.size() );

  REQUIRE(0 == ranks[0].first);
  REQUIRE(5 == ranks[0].second);

  REQUIRE(6 == ranks[1].first);
  REQUIRE(11 == ranks[1].second);

  REQUIRE(12 == ranks[2].first);
  REQUIRE(17 == ranks[2].second);

  REQUIRE(18 == ranks[3].first);
  REQUIRE(20 == ranks[3].second);
}
//------------------------------------------------------------------------------
TEST_CASE("valid_2", "check valid") {
  RankerCfg rankerCfg;
  rankerCfg.setBegin(0);
  rankerCfg.setEnd(10);
  rankerCfg.setCount(3);

  auto const ranks = Ranker::doRank(rankerCfg);
  REQUIRE( 3 == ranks.size() );

  REQUIRE(0 == ranks[0].first);
  REQUIRE(3 == ranks[0].second);

  REQUIRE(4 == ranks[1].first);
  REQUIRE(7 == ranks[1].second);

  REQUIRE(8 == ranks[2].first);
  REQUIRE(10 == ranks[2].second);
}
//------------------------------------------------------------------------------
TEST_CASE("begin_great_end", "begin and and exchanged") {
  RankerCfg rankerCfg;
  rankerCfg.setBegin(20);
  rankerCfg.setEnd(10);
  rankerCfg.setCount(5);

  auto const ranks = Ranker::doRank(rankerCfg);
  REQUIRE( 0 == ranks.size() );
}
//------------------------------------------------------------------------------
TEST_CASE("zero_count", "count is set to zero or less") {
  RankerCfg rankerCfg;
  rankerCfg.setBegin(0);
  rankerCfg.setEnd(10);
  rankerCfg.setCount(0);

  auto const ranks = Ranker::doRank(rankerCfg);
  REQUIRE( 0 == ranks.size() );
}
//------------------------------------------------------------------------------
TEST_CASE("count_gt_length", "count is great length") {
  RankerCfg rankerCfg;
  rankerCfg.setBegin(0);
  rankerCfg.setEnd(10);
  rankerCfg.setCount(30);

  auto const ranks = Ranker::doRank(rankerCfg);
  REQUIRE( 11 == ranks.size() );

  for (size_t i = 0; i <= 10; ++i) {
    REQUIRE(i == ranks[i].first);
    REQUIRE(i == ranks[i].second);
  }
}
//------------------------------------------------------------------------------
