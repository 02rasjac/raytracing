#pragma once

#include <iostream>
#include "Vec3.h"

template<typename T>
class Matrix44 {
public:
	Matrix44() = default;
	const T* operator[](const uint8_t i) const { return m[i]; };
	T* operator[](const uint8_t i) { return m[i]; };
	Matrix44<T> operator*(const Matrix44<T> rhs) {
		Matrix44<T> mult;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mult[i][j] =
					m[i][0] * rhs[0][j] +
					m[i][1] * rhs[1][j] +
					m[i][2] * rhs[2][j] +
					m[i][3] * rhs[3][j];
			}
		}

		return mult;
	}
	/*
	* Perfom vector-matrix-multiplication, assuming the vector src = (x,y,z,1).
	* @param src Vector to multiply the matrix with.
	* @param dst Vector to save the result in.
	*/
	void multVecMat(const Vec3<T>& src, Vec3<T>& dst) const {
		dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0];
		dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1];
		dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2];
	}
	/*
	* Perfom vector-matrix-multiplication, taking into consideration the case of projection, i.e dst = (x', y', z' w').
	* @param src Vector to multiply the matrix with.
	* @param dst Vector to save the result in.
	*/
	void multVecMatProj(const Vec3<T>& src, Vec3<T>& dst) const {
		multiVecMat(src, dst);
		auto w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + m[3][3];
		if (w != 1 && w != 0) {
			dst.x /= w;
			dst.y /= w;
			dst.z /= w;
		}
	}
	/*
	* Perfom vector-matrix-multiplication, with no consideration for translation, only direction.
	* @param src Vector to multiply the matrix with.
	* @param dst Vector to save the result in.
	*/
	void multDirMat(const Vec3<T>& src, Vec3<T>& dst) const {
		dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0];
		dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1];
		dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2];
	}
	Matrix44<T> transpose() {
		Matrix44<T> mat;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat[j][i] = m[i][j];
			}
		}
		return mat;
	}
private:
	T m[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} }; // Initialise with identitymatrix
};

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Matrix44<T>& mat) {
	return out 
		<< "(" << mat[0][0] << ", " << mat[0][1] << ", " << mat[0][2] << ", " << mat[0][3] << ")" << std::endl
		<< "(" << mat[1][0] << ", " << mat[1][1] << ", " << mat[1][2] << ", " << mat[1][3] << ")" << std::endl
		<< "(" << mat[2][0] << ", " << mat[2][1] << ", " << mat[2][2] << ", " << mat[2][3] << ")" << std::endl
		<< "(" << mat[3][0] << ", " << mat[3][1] << ", " << mat[3][2] << ", " << mat[3][3] << ")" << std::endl;
}
