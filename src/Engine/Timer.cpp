#include "Engine/Timer.hpp"

namespace Engine {
    Timer::Timer() {
        gettimeofday(&this->time, NULL);
        //clock_gettime(CLOCK_REALTIME, &ts);
    }

    Timer::~Timer() {

    }

    void Timer::reset() {
        gettimeofday(&this->time, NULL);
        //clock_gettime(CLOCK_REALTIME, &ts);
    }

    timeval Timer::getTime() {
        timeval currentTime;
        gettimeofday(&currentTime, NULL);

        return currentTime;
    }

    long Timer::getLapsed() {
        //timespec time;
        //clock_gettime(CLOCK_REALTIME, &time);
        timeval newTime;
        gettimeofday(&newTime, NULL);

        return (long)((long)(newTime.tv_sec * 1000) + (long)(newTime.tv_usec / 1000)) -
            (long)((long)(this->time.tv_sec * 1000) + (long)(this->time.tv_usec / 1000));
    }

    unsigned int Timer::getLapsedSec() {
        //timespec time;
        //clock_gettime(CLOCK_REALTIME, &time);
        timeval newTime;
        gettimeofday(&newTime, NULL);

        return (long)(newTime.tv_sec - this->time.tv_sec);
    }

}
