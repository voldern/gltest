#ifndef __ENGINE_TIMER_HPP__
#define __ENGINE_TIMER_HPP__

#include <cstddef>
#include <sys/time.h>

namespace Engine {
    class Timer {
    public:
        Timer();
        ~Timer();

        void reset();
        timeval getTime();
        long getLapsed();
        unsigned int getLapsedSec();

    private:
        timeval time;
    };
}

#endif
