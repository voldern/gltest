#include "IntroScene.hpp"

void IntroScene::init() {
    this->shaderProgram = createProgram("./shaders/vertex.glsl",
                                        "./shaders/fragment.glsl");
    float vertices[] = {
      0.0f,  0.5f, // Vertex 1 (X, Y)
      0.5f, -0.5f, // Vertex 2 (X, Y)
      -0.5f, -0.5f  // Vertex 3 (X, Y)
    };

    GLuint vbo;
    glGenBuffers(1, &vbo); // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);   
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(float),
                 vertices, GL_STATIC_DRAW);
}

void IntroScene::draw() {
  glUseProgram(this->shaderProgram);
  GLint posAttrib = glGetAttribLocation(this->shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);
  
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void IntroScene::update() {

}
