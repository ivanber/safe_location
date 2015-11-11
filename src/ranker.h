#ifndef RANKER_H__
#define RANKER_H__
//------------------------------------------------------------------------------
#include <vector>
//------------------------------------------------------------------------------
class RankerCfg {
public:
  RankerCfg() : fBegin(0), fEnd(0), fCount(0) {}

  int begin() const { return fBegin; }
  void setBegin(int const aVal) { fBegin = aVal; }

  int end() const { return fEnd; }
  void setEnd(int const aVal) { fEnd = aVal; }

  int count() const { return fCount; }
  void setCount(int const aVal) { fCount = aVal; }
private:
  int fBegin;
  int fEnd;
  int fCount;
};
//------------------------------------------------------------------------------
class Ranker {
public:
  typedef std::pair< int, int > Rank;
  typedef std::vector< Rank > Ranks;
public:
  static Ranks doRank(RankerCfg const &aCfg);
};
//------------------------------------------------------------------------------
#endif
