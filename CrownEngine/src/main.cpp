#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "glad.h"
#include <GLFW/glfw3.h>

#include <constants.h>

//Reads the contents of the file at programDirectory/name and returns it as a string
std::string readFile(std::string name) {
    std::ifstream fileStream(name);

    if (!fileStream.is_open()) {
        std::cout << "File not found." << std::endl;
        return nullptr;
    }

    std::stringstream out;

    std::string line;
    while (getline(fileStream, line)) {
        out << line << "\n";
    }

    fileStream.close();

    return out.str();
}

//
unsigned int compileVertexShader(std::string name) {
    std::string vertexShaderSource = readFile(name);

    //Create a vertex shader object
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char* vertexShaderSourceCStr = vertexShaderSource.c_str();

    //Compile the shader
    glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int createVertexShader(std::string name) {
    unsigned int vertexShader = compileVertexShader(name);
    
    //Verify the shader actually compiled before making it
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        std::cout << "Shader compilation failed." << std::endl;
        return -1;
    }

    return vertexShader;
}

unsigned int compileFragmentShader(std::string name) {
    std::string fragShaderSource = readFile(name);

    //Create a new fragment shader object
    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* fragShaderSourceCStr = fragShaderSource.c_str();

    //Compile the shader
    glShaderSource(fragShader, 1, &fragShaderSourceCStr, nullptr);
    glCompileShader(fragShader);

    return fragShader;
}

unsigned int createFragmentShader(std::string name) {
    unsigned int fragShader = compileFragmentShader(name);
    
    //Verify the shader actually compiled before making it
    int success;
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        std::cout << "Shader compilation failed." << std::endl;
        return -1;
    }

    return fragShader;
}

void createShaderProgram() {
    //Create our shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    
    //Load the vertex and fragment shader
    unsigned int vertexShader = createVertexShader("../src/effects/simple.vert");
    unsigned int fragmentShader = createFragmentShader("../src/effects/simple.frag");
    
    //Bind the shaders to our program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    
    //Set up the program and use it
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    
    //We've linked the shaders to the program so we destruct them
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
}

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