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
        GLuint program;
        Shader* fragmentShader;
        Shader* vertexShader;

    public:
        Program();
        ~Program();

        void attachVertexShader(Shader* shader);
        void attachFragmentShader(Shader* shader);
        bool link();
    
        GLuint getProgram();
        Shader* getVertexShader();
        Shader* getFragmentShader();
    };
}

#endif
