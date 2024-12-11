#ifndef _RAY_H
#define _RAY_H

#include "geometry.h"
#include "glm/glm.hpp"

namespace raytracer {

class Ray {
public:
    Ray(glm::vec3 a_direction, glm::vec3 a_color, float a_luminosity);

    void traceRay();

private:
    glm::vec3 m_direction;
    glm::vec3 m_color;
    float m_luminosity; // once luminosity reaches a threshold, stop tracing the ray

    bool checkForCollision();
};
}

#endif // _RAY_H