cmake_minimum_required(VERSION 3.10)
project(Buffer)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake that "include/" is an include search path
include_directories(include)

# Tell CMake where the source files are
add_executable(Buffer
    src/main.cpp
)
