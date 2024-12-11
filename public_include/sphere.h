#ifndef _SPHERE_H
#define _SPHERE_H

#include "geometry.h"
#include "glm/glm.hpp"
namespace raytracer {

struct Sphere : Geometry {
    float radius;
};
}
#endif // _SPHERE_H