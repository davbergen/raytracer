# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(RayTracer)

# Specify the C++ standard (optional but recommended)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files to the project
add_executable(RayTracer src/main.cpp)

