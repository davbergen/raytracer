# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# Set the project name
project(RayTracer)

# Add the subdirectory for GLM
add_subdirectory(modules/glm)

# Specify the C++ standard (optional but recommended)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the source files to the project
add_executable(raytracer src/main.cpp src/camera.cpp src/ray.cpp src/scene.cpp)

target_link_libraries(raytracer glm)


target_include_directories(raytracer PRIVATE modules/headers public_include)

