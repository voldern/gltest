#ifndef __ENGINE_PROGRAM_HPP__
#define __ENGINE_PROGRAM_HPP__

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "Engine/Shader.hpp"

namespace Engine {
  class Program {
  private:
    std::vector<Shader*> shaders;

  public:
    Program();
    ~Program();

    void attachShader(Shader* shader);
    
    GLuint getLinkedProgram();
  };
}

#endif
