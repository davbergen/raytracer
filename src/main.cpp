#define STB_IMAGE_WRITE_IMPLEMENTATION

// external libraries
#include "glm/glm.hpp"
#include "stb_image_write.h"

// c++ libraries
#include <iostream>
#include <memory>
#include <vector>

// project headers
#include "constants.h"
#include "scene.h"
#include "sphere.h"

void setVectorElementByCoordinates(std::vector<unsigned char>& r_vector, int a_x, int a_y, int a_channel, unsigned char a_value)
{
    r_vector[(a_x + a_y * c_xSize) * c_channels + a_channel] = a_value;
}

using namespace raytracer;

void initializeScene(Scene& r_scene)
{
    // TODO: Hardcoded for now --> Read this from file or config some other way

    // Create a sphere
    std::shared_ptr<Sphere> sphere = std::make_shared<Sphere>();
    glm::vec3 spherePos { 0, 0, 0 };
    glm::vec3 sphereColor { 255, 0, 0 };
    sphere->material.color = sphereColor;
    sphere->position = spherePos;
    sphere->radius = 2;
    r_scene.addGeometryToScene(sphere);

    // // Create the camera
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(c_xSize, c_ySize, c_channels, glm::vec3(0, 0, -10), glm::vec3(0, 0, 1));
    r_scene.addCameraToScene(camera);
}

int main()
{
    Scene scene {};
    initializeScene(scene);

    std::shared_ptr<Camera> camera = scene.getCamera();

    camera->render();

    std::vector<unsigned char> canvas(c_xSize * c_ySize * c_channels);

    std::cout << "Hello, World!" << std::endl;
    for (int y = 0; y < c_ySize; ++y) {
        for (int x = 0; x < c_xSize; ++x) {
            setVectorElementByCoordinates(canvas, x, y, 0, x);
            setVectorElementByCoordinates(canvas, x, y, 1, y);
            setVectorElementByCoordinates(canvas, x, y, 2, x + y % 256);
        }
    }

    stbi_write_png("../generated/image.png", c_xSize, c_ySize, c_channels, canvas.data(), c_xSize * c_channels);
    return 0;
}