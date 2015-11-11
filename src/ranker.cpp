#include "ranker.h"
//------------------------------------------------------------------------------
Ranker::Ranks Ranker::doRank(RankerCfg const &aCfg) {
  Ranks ranks;

  auto const count = aCfg.count();
  if (count > 0) {
    auto const begin = aCfg.begin();
    auto const end = aCfg.end();

    auto const len = end - begin;
    auto const rankMaxLen = len / count;
    auto rankBegin = begin;
    while (rankBegin <= len) {
      auto rankEnd = rankBegin + rankMaxLen;
      if (rankEnd > end) {
        rankEnd = end;
      }

      ranks.push_back( Rank(rankBegin, rankEnd) );

      rankBegin = rankEnd + 1;
    }
  }

  return ranks;
}
//------------------------------------------------------------------------------
