#include "glm/glm.hpp"
#include <iostream>

int main()
{
    std::cout << "Hello, World! The sin of 90 degrees is about " << glm::sin(glm::radians(90.f)) << std::endl;
    return 0;
}