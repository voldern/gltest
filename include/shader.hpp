#ifndef __ENGINE_SHADER_HPP__
#define __ENGINE_SHADER_HPP__

#include <string>
#include <GL/glew.h>
#include <GL/glfw.h>

namespace Engine {
  class Shader {
  private:
    std::string filename;
    std::string shaderSource;
    GLuint shader;
    
    std::string loadShaderFile();

  public:
    enum Type {
      Vertex,
      Fragment
    } shaderType;
    
    Shader(std::string filename, Type shaderType);
    bool compileShader();
    GLuint getShader();
    std::string getShaderSource();
  };
}

#endif
