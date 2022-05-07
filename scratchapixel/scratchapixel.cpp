#include <iostream>

#include "vec3.h"

int main() {
    point3i intVec(1);
    vec3f floVec(1.2f, -1.7f, 0.0f);
    vec3d douVec(0.0, 5.2, -2.3);

    std::cout << intVec << floVec << douVec << std::endl;
}