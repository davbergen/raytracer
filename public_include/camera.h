#ifndef _CAMERA_H
#define _CAMERA_H

#include "glm/glm.hpp"
#include <vector>

namespace raytracer {
class Camera {
public:
    Camera(int a_screenWidth, int a_screenHeight, int a_numChannels, glm::vec3 a_position, glm::vec3 a_direction);

    void render();

    glm::vec3 getPixelValueRGB(int a_x, int a_y);
    glm::vec4 getPixelValueRGBA(int a_x, int a_y);
    glm::vec3 getPosition()
    {
        return m_position;
    }

private:
    int m_screenWidth;
    int m_screenHeight;
    int m_numChannels;
    glm::vec3 m_position;
    glm::vec3 m_direction;
    std::vector<unsigned char> m_canvas;
};
}

#endif // _CAMERA_H