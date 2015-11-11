#ifndef MY_TIMER_H__
#define MY_TIMER_H__
//------------------------------------------------------------------------------
#include <chrono>
#include <ctime>
#include <ratio>
//------------------------------------------------------------------------------
class MyTimer {
public:
  MyTimer() {
    fBegin = std::chrono::high_resolution_clock::now();
  }

  double elapsedMs() {
    auto const now = std::chrono::high_resolution_clock::now();
    auto const diff = now - fBegin;
    return std::chrono::duration< double, std::milli >(diff).count();
  }
private:
  std::chrono::high_resolution_clock::time_point fBegin;
};
//------------------------------------------------------------------------------
#endif
