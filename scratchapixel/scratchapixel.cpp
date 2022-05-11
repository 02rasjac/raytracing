#include <iostream>

#include "Vec3.h"
#include "Matrix44.h"

int main() {
    // Test vectors
    Point3i intVec(1);
    Vec3f floVec(1.2f, -1.7f, 0.0f);
    Vec3d douVec1(1.0, 5.0, -2.0);
    Vec3d douVec2(2.0, 2.0, 3.0);

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

    // Test matricies
    Matrix44<int> mat1;
    Matrix44<int> mat2;
    auto counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++, counter++) {
            mat1[i][j] = counter;
            mat2[i][j] = counter - j;
        }
    }
    std::cout << mat1 << std::endl;
    std::cout << mat2 << std::endl;

    auto mult = mat1 * mat2;
    std::cout << mult << std::endl;
    
    mat1 = mat1.transpose();
    std::cout << mat1 << std::endl;
}