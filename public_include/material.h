#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "glm/glm.hpp"
namespace raytracer {
struct Material {
    glm::vec3 color;
    float absorption;
};
}

#endif // _MATERIAL_H