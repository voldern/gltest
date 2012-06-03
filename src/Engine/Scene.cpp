#include "Engine/Scene.hpp"

namespace Engine {
    Scene::Scene(Timer &timer, unsigned int startTime, unsigned int stopTime) {
    this->timer = timer;
    this->startTime = startTime;
    this->stopTime = stopTime;
  }
  
  unsigned int Scene::getStartTime() {
    return this->startTime;
  }

  unsigned int Scene::getStopTime() {
    return this->stopTime;
  }
}
