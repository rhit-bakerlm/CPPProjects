#include <string>
#include <fstream>
#include <iostream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include <shaders.h>
#include <utils.h>

//Compiles a vertex shader and returns its GLFW binding
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

//Creates a vertex shader and returns its GLFW binding
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

//Compiles a fragment shader and returns its GLFW binding
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

//Creates a fragment shader and returns its GLFW binding
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