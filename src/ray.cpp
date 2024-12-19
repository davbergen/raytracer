#include "ray.h"
namespace raytracer {

Ray::Ray(glm::vec3 a_position, glm::vec3 a_direction)
    : m_position(a_position)
    , m_direction(a_direction)
{
}

void Ray::traceRay()
{
}
}