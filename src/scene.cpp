#include "scene.h"
namespace raytracer {

Scene::Scene()
{
    m_geometries = {};
}

void Scene::addGeometryToScene(std::shared_ptr<Geometry> a_geometry)
{
    m_geometries.push_back(a_geometry);
}

void Scene::addCameraToScene(std::shared_ptr<Camera> a_camera)
{
    m_camera = a_camera;
}

std::shared_ptr<Camera> Scene::getCamera()
{
    return m_camera;
}
}
