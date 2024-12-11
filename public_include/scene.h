#ifndef _SCENE_H
#define _SCENE_H

#include "camera.h"
#include "geometry.h"
#include <memory>
#include <vector>

namespace raytracer {
class Scene {
public:
    Scene();
    void addGeometryToScene(std::shared_ptr<Geometry> a_geometry);
    void addCameraToScene(std::shared_ptr<Camera> a_camera);
    std::shared_ptr<Camera> getCamera();

private:
    std::vector<std::shared_ptr<Geometry>> m_geometries;
    std::shared_ptr<Camera> m_camera;
};
}

#endif // _SCENE_H