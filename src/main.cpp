#define STB_IMAGE_WRITE_IMPLEMENTATION

// external libraries
#include "glm/glm.hpp"
#include "stb_image_write.h"

// c++ libraries
#include <iostream>
#include <vector>

// project headers
#include "constants.h"

void setVectorElementByCoordinates(std::vector<unsigned char>& r_vector, int a_x, int a_y, int a_channel, unsigned char a_value)
{
    r_vector[(a_x + a_y * c_xSize) * c_channels + a_channel] = a_value;
}

int main()
{
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