#include "Engine/Shader.hpp"

namespace Engine {
  Shader::Shader(std::string filename, Shader::Type shaderType) {
    this->filename = filename;
    this->shaderType = shaderType;
    this->shaderSource = this->loadShaderFile();
  }

  bool Shader::compileShader() {
    const char* shaderSource = (const char*)this->shaderSource.c_str();

    // const char* shaderSource
    // if (this->shaderType == Shader::Vertex) {
    //   shaderSource = "#version 150\nin vec2 position; void main() { gl_Position = vec4( position, 0.0, 1.0 ); }";
    // } else if (this->shaderType == Shader::Fragment) {
    //   shaderSource = "#version 150\nout vec4 outColor; void main() { outColor = vec4( 1.0, 1.0, 1.0, 1.0 ); }";
    // }
    // const char* shaderSource = readShader(filename);
    
    GLuint shader;
    if (this->shaderType == Shader::Vertex) {
      shader = glCreateShader(GL_VERTEX_SHADER);
    } else if (this->shaderType == Shader::Fragment) {
      shader = glCreateShader(GL_FRAGMENT_SHADER);
    } else {
      throw std::string("Unknown shader type");
    }

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

    this->shader = shader;
    return true;
  }

  GLuint Shader::getShader() {
    return this->shader;
  }

  std::string Shader::getSource() {
    return this->shaderSource;
  }

  std::string Shader::loadShaderFile() {
    std::fstream shaderFile(this->filename.c_str());
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
    
    return shader;
  }
}
