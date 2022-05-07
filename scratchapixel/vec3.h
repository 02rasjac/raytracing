#pragma once

#include <iostream>

template<typename T>
class vec3 {
public:
	vec3() : x(0), y(0), z(0) {};
	vec3(const T& xx) : x(xx), y(xx), z(xx) {};
	vec3(const T& xx, const T& yy, const T& zz) : x(xx), y(yy), z(zz) {};
public:
	T x, y, z;
};

typedef vec3<int>	 vec3i, point3i;
typedef vec3<float>	 vec3f, point3f;
typedef vec3<double> vec3d, point3d;

// =================
// Utility functions
// =================

inline std::ostream& operator<<(std::ostream& out, vec3i& vec) {
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

inline std::ostream& operator<<(std::ostream& out, vec3f& vec) {
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

inline std::ostream& operator<<(std::ostream& out, vec3d& vec) {
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}
