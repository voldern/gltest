#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "main.hpp"
#include "util.hpp"

float vertices[] = {
    0.0f,  0.5f, // Vertex 1 (X, Y)
    0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
};

int main() {
    glfwInit();

    glfwOpenWindowHint( GLFW_OPENGL_VERSION_MAJOR, 3 );
    glfwOpenWindowHint( GLFW_OPENGL_VERSION_MINOR, 2 );
    glfwOpenWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    
    glfwOpenWindowHint( GLFW_WINDOW_NO_RESIZE, GL_TRUE );
    glfwOpenWindow( 800, 600, 0, 0, 0, 0, 0, 0, GLFW_WINDOW );

    glfwSetWindowTitle( "OpenGL play" );

    GLenum glewErr = glewInit();
    if (glewErr != GLEW_OK) {
        std::cout << "GLEW error: " << glewGetErrorString(glewErr) << std::endl;
        return 1;
    }

    // HACK: For some unknow reason glewInit generates a 1280 GL error
    // so we need to clear that here.
    glGetError();

    GLuint vbo;
    glGenBuffers(1, &vbo); // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);   
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(float),
                 vertices, GL_STATIC_DRAW);

    GLuint shaderProgram;
    try {
        shaderProgram = createProgram("./shaders/vertex.glsl",
                                      "./shaders/fragment.glsl");
    } catch (std::string ex) {
        std::cout << ex << std::endl;
        return 1;
    }

    glUseProgram(shaderProgram);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glEnableVertexAttribArray(posAttrib);

    while(glfwGetWindowParam(GLFW_OPENED)) {
        if ( glfwGetKey( GLFW_KEY_ESC ) == GLFW_PRESS ) {
            break;
        }

        glDrawArrays(GL_TRIANGLES, 0, 3);
    
        glfwSwapBuffers();
    }
  
    glfwTerminate();
  
    return 0;
}
