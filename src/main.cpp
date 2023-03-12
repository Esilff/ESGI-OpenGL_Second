#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <array>
#include <iostream>
#include "core/Shader.h"
#include "core/Mesh.h"

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
};




int main() {
    GLFWwindow * window;
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    window = glfwCreateWindow(640,480, "ESGI-OpenGL_Project_dev", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize the window");
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGL()) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    Mesh mesh = Mesh(vertices, 3, shader::Shader("src/shaders/basic.glsl"));


    while(!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glClearColor(0.1,0.1,0.1,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.bind();
        mesh.draw(GL_TRIANGLES);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
