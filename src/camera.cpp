#include "camera.h"
#include "memory"
#include "ray.h"
#include <iostream>

namespace raytracer {
Camera::Camera(int a_screenWidth, int a_screenHeight, int a_numChannels, glm::vec3 a_position, glm::vec3 a_direction, float a_focalLength, float a_fov)
    : m_screenWidth(a_screenWidth)
    , m_screenHeight(a_screenHeight)
    , m_numChannels(a_numChannels)
    , m_position(a_position)
    , m_direction(a_direction)
    , m_fov(a_fov)
    , m_focalLength(a_focalLength)
    , m_canvas(m_screenWidth * m_screenHeight * m_numChannels)
{
    m_viewplane.height = 2.f * m_focalLength * glm::tan(m_fov / 2);
    m_viewplane.width = m_viewplane.height * m_screenWidth / m_screenHeight;
    m_viewplane.position = glm::vec3(m_position.x, m_position.y, m_position.z - m_focalLength);
}

glm::vec3 Camera::getPixelWorldLocationFrom2DCoords(float a_x, float a_y)
{
    // viewplane position span between [-1, 1] in both x- and y-direction
    float x = m_position.x - 1 + a_x / m_viewplane.height / (m_viewplane.height / 2); // no
    float y = m_position.y - 1 + a_y / m_viewplane.width / (m_viewplane.width / 2);
    float z = m_position.z - m_focalLength;
    return glm::vec3(x, y, z);
}

void Camera::render()
{
    std::cout << m_screenHeight << std::endl;
    std::cout << m_screenWidth << std::endl;
    // shoot ray from each pixel
    for (int y = 0; y < m_screenHeight; ++y) {
        for (int x = 0; x < m_screenWidth; ++x) {
            glm::vec3 pixelWorldPosition(getPixelWorldLocationFrom2DCoords(x, y));
            std::cout << pixelWorldPosition.x << ", " << pixelWorldPosition.y << ", " << pixelWorldPosition.z << std::endl;
            std::shared_ptr<Ray> ray = std::make_shared<Ray>(m_position, glm::normalize(pixelWorldPosition - m_position));
        }
    }
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