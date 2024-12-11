#include "camera.h"
#include <iostream>

namespace raytracer {
Camera::Camera(int a_screenWidth, int a_screenHeight, int a_numChannels, glm::vec3 a_position, glm::vec3 a_direction)
    : m_screenWidth(a_screenWidth)
    , m_screenHeight(m_screenHeight)
    , m_numChannels(a_numChannels)
    , m_position(a_position)
    , m_direction(a_direction)
    , m_canvas(m_screenWidth * m_screenHeight * m_numChannels)
{
}

void render()
{
    // shoot ray from each pixel
    // check for ray-collisions in scene
    // accumulate color of ray depending on collision, absorption/reflection of material
}

glm::vec3 Camera::getPixelValueRGB(int a_x, int a_y)
{
}

glm::vec4 Camera::getPixelValueRGBA(int a_x, int a_y)
{
    std::cout << "getPixelValueRGBA: Not implemented yet" << std::endl;
}
}