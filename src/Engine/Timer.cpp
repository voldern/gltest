#include "Engine/Timer.hpp"

namespace Engine {
  Timer::Timer() {
    clock_gettime(CLOCK_REALTIME, &ts);
  }

  Timer::~Timer() {

  }

  void Timer::reset() {
    clock_gettime(CLOCK_REALTIME, &ts);
  }

  long Timer::getLapsed() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    
    return (long)(time.tv_nsec - this->ts.tv_nsec);
  }

  unsigned int Timer::getLapsedSec() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    
    return (long)(time.tv_sec - this->ts.tv_sec);
  }
  
}
