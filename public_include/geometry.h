#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "glm/glm.hpp"
#include "material.h"

namespace raytracer {

struct Geometry {
    glm::vec3 position;
    Material material;
};
}

#endif // _GEOMETRY_H