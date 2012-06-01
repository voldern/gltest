#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "util.hpp"
#include "Shader.hpp"


GLuint createProgram(const char *vShaderPath, const char *fShaderPath) {
  Engine::Shader vShader(vShaderPath, Engine::Shader::Vertex);
  Engine::Shader fShader(fShaderPath, Engine::Shader::Fragment);

  // This can throw an exception
  vShader.compileShader();
  fShader.compileShader();
  
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vShader.getShader());
  glAttachShader(shaderProgram, fShader.getShader());
  
  glBindFragDataLocation(shaderProgram, 0, "outColor");
    
  glLinkProgram(shaderProgram);

  return shaderProgram;
}

