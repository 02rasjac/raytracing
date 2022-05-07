#include <iostream>

#include "vec3.h"

int main() {
    point3i intVec(1);
    vec3f floVec(1.2f, -1.7f, 0.0f);
    vec3d douVec1(1.0, 5.0, -2.0);
    vec3d douVec2(2.0, 2.0, 3.0);

    auto c1 = cross(douVec1, douVec2);
    auto c2 = douVec1.cross(douVec2);
    auto v1 = -douVec1;
    auto v2 = douVec1 + douVec2;
    auto v3 = douVec1 - douVec2;
    std::cout << intVec << floVec << douVec1 << std::endl;
    std::cout << floVec.normalize() << std::endl;
    std::cout << dot(douVec1, douVec2) << std::endl;
    std::cout << douVec1.dot(douVec2) << std::endl;
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << v1 << ' ' << v2 << ' ' << v3 << std::endl;
}