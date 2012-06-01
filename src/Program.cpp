#include "Program.hpp"

namespace Engine {
  Program::Program() {
  }

  Program::~Program() {
    
  }

  void Program::attachShader(Shader* shader) {
    this->shaders.push_back(shader);
  }
  
  GLuint Program::getLinkedProgram() {
    GLuint program = glCreateProgram();
    for (std::vector<Shader*>::iterator shader = this->shaders.begin();
         shader != this->shaders.end();
         shader++) {
      glAttachShader(program, (*shader)->getShader());
    }

    glBindFragDataLocation(program, 0, "outColor");
    
    glLinkProgram(program);
    
    return program;
  }
}
