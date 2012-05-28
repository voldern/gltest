#include <GL/glfw.h>

const char* readShader(const char* filename);
GLuint loadShader(const char* filename, unsigned int test);
GLuint createProgram(const char *vShader, const char *fShader);
