#pragma once

//Compiles a vertex shader and returns its GLFW binding
unsigned int compileVertexShader(std::string name);

//Creates a vertex shader and returns its GLFW binding
unsigned int createVertexShader(std::string name);

//Compiles a fragment shader and returns its GLFW binding
unsigned int compileFragmentShader(std::string name);

//Creates a fragment shader and returns its GLFW binding
unsigned int createFragmentShader(std::string name);

void createShaderProgram();