#ifndef __INTRO_SCENE_HPP__
#define __INTRO_SCENE_HPP__

#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Engine/Scene.hpp"
#include "util.hpp"


class IntroScene: public Engine::Scene {
public:
  IntroScene(Engine::Timer &timer, unsigned int startTime, unsigned int endTime)
    : Scene(timer, startTime, endTime) {}
  void init();
  void update();
  void draw();

private:
  GLuint shaderProgram;
  glm::mat4 Model;
  glm::mat4 View;
  glm::mat4 Projection;
  
};

#endif
