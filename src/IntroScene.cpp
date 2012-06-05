#include <iostream>

#include "IntroScene.hpp"

void IntroScene::init() {
    this->shaderProgram = createProgram("./shaders/vertex.glsl",
                                        "./shaders/fragment.glsl");

    static const GLfloat vertexPositions[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    glGenBuffers(1, &this->vbo);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    this->Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    this->View = glm::lookAt(
                             glm::vec3(0,0,-4), // Camera is at (4,3,3), in World Space
                             glm::vec3(0,0,0), // and looks at the origin
                             glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
                             );
    
    // this->Model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 5.0f)); // Changes for each model !
}

void IntroScene::draw() {
    glUseProgram(this->shaderProgram);

    this->Model = glm::rotate(this->Model, (float)(this->timer.getLapsed() / 400),
                              glm::vec3(0.0f, 0.0f, 1.0f));
  
    glm::mat4 MVP = this->Projection * this->View * this->Model;
    

    GLuint MatrixID = glGetUniformLocation(this->shaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    // GLint posAttrib = glGetAttribLocation(this->shaderProgram, "position");
    // glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    // glEnableVertexAttribArray(posAttrib);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(0);
    glUseProgram(0);
}

void IntroScene::update() {
    std::cout << "Lapsed: " << this->timer.getLapsed() << std::endl;
    if (this->timer.getLapsed() > 2000) {
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
