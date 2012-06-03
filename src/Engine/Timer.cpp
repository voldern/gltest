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
    
    timespec diff;
    if ((time.tv_nsec - this->ts.tv_nsec) < 0) {
      diff.tv_sec = time.tv_sec - this->ts.tv_sec-1;
      diff.tv_nsec = 1000000000 + time.tv_nsec - this->ts.tv_nsec;
    } else {
      diff.tv_sec = time.tv_sec - this->ts.tv_sec;
      diff.tv_nsec = time.tv_nsec - this->ts.tv_nsec;
    }
    
    return diff.tv_nsec;
  }

  unsigned int Timer::getLapsedSec() {
    timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    
    return (long)(time.tv_sec - this->ts.tv_sec);
  }
  
}
