#include <iostream>

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

  this->Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
  // Camera matrix
  this->View = glm::lookAt(
                           glm::vec3(0,0,-4), // Camera is at (4,3,3), in World Space
                           glm::vec3(0,0,0), // and looks at the origin
                           glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
                           );
  
  this->Model = glm::mat4(1.0f);
}

void IntroScene::draw() {
  glUseProgram(this->shaderProgram);

  this->Model = glm::rotate(glm::mat4(1.0f), (float)((this->timer.getLapsed() / 1000000) / 2),
                                glm::vec3(0.0f, 0.0f, 1.0f));
  
  glm::mat4 MVP = this->Projection * this->View * this->Model;

  GLuint MatrixID = glGetUniformLocation(this->shaderProgram, "MVP");
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
  
  GLint posAttrib = glGetAttribLocation(this->shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);
  
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void IntroScene::update() {
  std::cout << "Lapsed: " << this->timer.getLapsedSec() << std::endl;
  if (this->timer.getLapsedSec() > 2) {
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }
}
