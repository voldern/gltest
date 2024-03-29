#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "util.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Program.hpp"


GLuint createProgram(const char *vShaderPath, const char *fShaderPath) {
    Engine::Shader* vShader = new Engine::Shader(vShaderPath, Engine::Shader::Vertex);
    Engine::Shader* fShader = new Engine::Shader(fShaderPath, Engine::Shader::Fragment);

    // This can throw an exception
    vShader->compileShader();
    fShader->compileShader();

    Engine::Program shaderProgram;
    shaderProgram.attachVertexShader(vShader);
    shaderProgram.attachFragmentShader(fShader);
    shaderProgram.link();
    
    return shaderProgram.getProgram();
}

