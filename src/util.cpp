#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "util.hpp"

const char* readShader(const char* filename) {
  std::fstream shaderFile(filename);
  std::ostringstream buffer;

  if (!shaderFile.is_open() || !shaderFile.good()) {
    std::stringstream error;
    error << "Could not load shader " << filename << std::endl;
    
    throw std::string(error.str());
  }

  std::string shader;

  shaderFile.seekg(0, std::ios::end);
  shader.reserve(shaderFile.tellg());
  shaderFile.seekg(0, std::ios::beg);

  shader.assign((std::istreambuf_iterator<char>(shaderFile)),
                std::istreambuf_iterator<char>());

  shaderFile.close();

  return shader.c_str();
}

GLuint loadShader(const char* filename, GLenum shaderType) {
  const char* shaderSource;
  if (shaderType == GL_VERTEX_SHADER) {
    shaderSource = "#version 150\nin vec2 position; void main() { gl_Position = vec4( position, 0.0, 1.0 ); }";
  } else if (shaderType == GL_FRAGMENT_SHADER) {
    shaderSource = "#version 150\nout vec4 outColor; void main() { outColor = vec4( 1.0, 1.0, 1.0, 1.0 ); }";
  }
  // const char* shaderSource = readShader(filename);
  GLuint shader = glCreateShader(shaderType);

  glShaderSource(shader, 1, &shaderSource, NULL);
  
  glCompileShader(shader);

  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

  if (status != GL_TRUE) {
    std::ostringstream error;    
    char buffer[513];
    glGetShaderInfoLog(shader, 512, NULL, buffer);

    error << "Shader source:" << std::endl << shaderSource << std::endl << buffer;
    
    throw std::string(error.str());
  }

  return shader;
}

GLuint createProgram(const char *vShaderPath, const char *fShaderPath) {
  GLuint vShader = loadShader(vShaderPath, GL_VERTEX_SHADER);
  GLuint fShader = loadShader(fShaderPath, GL_FRAGMENT_SHADER);

  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vShader);
  glAttachShader(shaderProgram, fShader);
  
  glBindFragDataLocation(shaderProgram, 0, "outColor");
    
  glLinkProgram(shaderProgram);

  return shaderProgram;
}

