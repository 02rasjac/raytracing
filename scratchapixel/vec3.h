#pragma once

#include <iostream>
#include <cmath>

template<typename T>
class Vec3 {
public:
	Vec3() : x(0), y(0), z(0) {};
	Vec3(const T& xx) : x(xx), y(xx), z(xx) {};
	Vec3(const T& xx, const T& yy, const T& zz) : x(xx), y(yy), z(zz) {};
	T length() const {
		return sqrt(x * x + y * y + z * z);
	}
	T lengthSquared() const {
		return x * x + y * y + z * z;
	};
	/*
	* Normalize this vector
	* @return A reference to this vector after it been normalized
	*/
	Vec3<T>& normalize() {
		T len = length();
		// Prevent division by zero
		if (len > 0) {
			T invLength = 1 / length();
			x *= invLength, y *= invLength, z *= invLength;
		}
		return *this;
	}
	T dot(const Vec3<T> u) const {
		return x * u.x + y * u.y + z * u.z;;
	}
	Vec3<T> cross(const Vec3<T>& u) {
		return Vec3<T>(
			y * u.z - z * u.y,
			z * u.x - x * u.z,
			x * u.y - y * u.x
		);
	}
public:
	T x, y, z;
};

typedef Vec3<int>	 Vec3i, Point3i;
typedef Vec3<float>	 Vec3f, Point3f;
typedef Vec3<double> Vec3d, Point3d;

// =================
// Utility functions
// =================

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Vec3<T>& vec) {
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

template<typename T>
inline Vec3<T> operator-(const Vec3<T>& u) {
	return Vec3<T>(-u.x, -u.y, -u.z);
}

template<typename T>
inline Vec3<T> operator+(const Vec3<T>& v, const Vec3<T>& u) {
	return Vec3<T>(
		v.x + u.x, 
		v.y + u.y, 
		v.z + u.z
	);
}

template<typename T>
inline Vec3<T> operator-(const Vec3<T>& v, const Vec3<T>& u) {
	return v + (-u);
}

template<typename T>
inline Vec3<T> operator*(const T t, const Vec3<T> v) {
	return Vec3<T>(t * v.x, t * v.y, t * v.z);
}

template<typename T>
inline Vec3<T> operator*(const Vec3<T> v, const double t) {
	return t*v;
}

template<typename T>
inline Vec3<T> operator/(const Vec3<T> v, const double t) {
	double invt = 1 / t;
	return invt * v;
}

template<typename T>
inline T dot(const Vec3<T>& v, const Vec3<T>& u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

template<typename T>
inline Vec3<T> cross(const Vec3<T>& v, const Vec3<T>& u) {
	return Vec3<T>(
		v.y * u.z - v.z * u.y, 
		v.z * u.x - v.x * u.z, 
		v.x * u.y - v.y * u.x
	);
}
