cmake_minimum_required(VERSION 3.10)
project(CrownEngine)
set(CMAKE_CXX_STANDARD 23)

# Make sure that we have OpenGL installed
find_package(OpenGL REQUIRED)

# Tell CMake that "include/" is an include search path
include_directories(include)

# For external libs
include_directories(external)

# Tell CMake where the source files are
add_executable(CrownEngine
    src/main.cpp

    src/shaders.cpp
    src/utils.cpp

    external/glad.c
)

# Add glfw as a dependency
target_link_libraries(CrownEngine
    glfw
    OpenGL::GL
)