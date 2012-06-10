#include "Engine/Program.hpp"

namespace Engine {
    Program::Program() {
        this->program = glCreateProgram();
    }

    Program::~Program() {
    
    }

    // TODO: Should it be possible to overwrite the shader?
    void Program::attachVertexShader(Shader* shader) {
        this->vertexShader = shader;
    }

    // TODO: Should it be possible to overwrite the shader?
    void Program::attachFragmentShader(Shader* shader) {
        this->fragmentShader = shader;
    }

    // TODO: Error handling
    bool Program::link() {
        if (this->vertexShader == NULL || this->fragmentShader == NULL) {
            // Throw error
        }

        glAttachShader(this->program, this->fragmentShader->getShader());
        glAttachShader(this->program, this->vertexShader->getShader());
        
        glBindFragDataLocation(this->program, 0, "outColor");
    
        glLinkProgram(this->program);

        return true;
    }
  
    GLuint Program::getProgram() {
        return this->program;
    }

    Shader* Program::getVertexShader() {
        return this->vertexShader;
    }

    Shader* Program::getFragmentShader() {
        return this->fragmentShader;
    }
}
