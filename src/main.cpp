#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "main.hpp"
#include "util.hpp"
#include "Engine/Scene.hpp"
#include "IntroScene.hpp"

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

    Engine::Timer timer;
    IntroScene introScene(timer, 0, 3);
    introScene.init();
    
    while(glfwGetWindowParam(GLFW_OPENED)) {
        if ( glfwGetKey( GLFW_KEY_ESC ) == GLFW_PRESS ) {
            break;
        }

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        unsigned int lapsedSec = timer.getLapsedSec();
        if (lapsedSec >= introScene.getStartTime() &&
            lapsedSec < introScene.getStopTime()) {
          
          std::cout << "Lapsed: " << timer.getLapsed() << std::endl;
          
          introScene.update();
          introScene.draw();
        }
    
        glfwSwapBuffers();
    }
  
    glfwTerminate();
  
    return 0;
}
