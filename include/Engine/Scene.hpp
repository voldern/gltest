#ifndef __ENGINE_SCENE_HPP__
#define __ENGINE_SCENE_HPP__

#include "Engine/Timer.hpp"

namespace Engine {
    class Scene {
    public:
      Scene(Timer &timer, unsigned int startTime, unsigned int stopTime);
      
      virtual void init() = 0;
      virtual void update() = 0;
      virtual void draw() = 0;

      unsigned int getStartTime();
      unsigned int getStopTime();

    protected:
      Timer timer;
      unsigned int startTime;
      unsigned int stopTime;
    };
}

#endif
