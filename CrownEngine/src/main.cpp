#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "constants.h"
#include "shaders.h"
#include "utils.h"

void drawSimpleTriangle() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    //Create a vertex buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    //Bind the vertex buffer and put our data into it
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Configure the vertex data pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    //And actually draw the object
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
    //If glfw doesn't open up right for some reason
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    //Make the window
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CrownEngine", nullptr, nullptr);

    //If we failed to make the window
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Bind the window
    glfwMakeContextCurrent(window);

    //Initialize GLAD before running any GLFW functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Create the shader program for the function before drawing
    createShaderProgram();

    //Main loop
    while (!glfwWindowShouldClose(window)) {
        //handle input here
        //...
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        //render stuff here
        //...
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawSimpleTriangle();

        //Refresh events and swap the buffer
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    //End the program and return
    glfwTerminate();
    return 0;
}