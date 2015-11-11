#ifndef MINER_MAXER_H__
#define MINER_MAXER_H__
//------------------------------------------------------------------------------
template < typename T >
class Miner {
public:
  Miner(T const &aInitValue) : fValue(aInitValue) {}

  T value() const { return fValue; }

  void setValue(T const aVal) {
    if (aVal < fValue) {
      fValue = aVal;
    }
  }
private:
  T fValue;
};
//------------------------------------------------------------------------------
template < typename T >
class Maxer {
public:
  Maxer(T const &aInitValue) : fValue(aInitValue) {}

  T value() const { return fValue; }

  void setValue(T const aVal) {
    if (aVal > fValue) {
      fValue = aVal;
    }
  }
private:
  T fValue;
};
//------------------------------------------------------------------------------
#endif
