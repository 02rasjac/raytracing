#pragma once

#include <iostream>

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
