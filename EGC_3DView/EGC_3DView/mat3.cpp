#include "mat3.h"
namespace egc {
	mat3& mat3::operator =(const mat3& srcMatrix) {
		for (int i = 0; i < 9; i++) {
			matrixData[i] = srcMatrix.matrixData[i];
		}
		return *this;
	}
	mat3 mat3::operator *(float scalarValue) const {
		mat3 res;
		for (int i = 0; i < 9; i++) {
			res.matrixData[i] = scalarValue * matrixData[i];
		}
		return res;
	}
	mat3 mat3::operator *(const mat3& srcMatrix) const {
		mat3 res;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				float sum = 0;
				for (int k = 0; k < 3; k++) {
					sum += matrixData[i * 3 + k] * srcMatrix.matrixData[k * 3 + j];
				}
				res.matrixData[i + 3 * j] = sum;
			}

		}
		return res;

	}
	vec3 mat3::operator *(const vec3& srcVector) const {

		vec3 res;
		res.x = matrixData[0] * srcVector.x + matrixData[3] * srcVector.y + matrixData[6] * srcVector.z;
		res.y = matrixData[1] * srcVector.x + matrixData[4] * srcVector.y + matrixData[7] * srcVector.z;
		res.z = matrixData[2] * srcVector.x + matrixData[5] * srcVector.y + matrixData[8] * srcVector.z;

		return res;

	}
	mat3 mat3::operator +(const mat3& srcMatrix) const {
		mat3 res;
		for (int i = 0; i < 9; i++) {
			res.matrixData[i] = srcMatrix.matrixData[i] + matrixData[i];
		}
		return res;

	}
	//get element by (row, column)
	float& mat3::at(int i, int j) {
		return matrixData[i + 3 * j];
	}
	const float& mat3::at(int i, int j) const {
		return matrixData[i + 3 * j];

	}
	float mat3::determinant() const {

		return matrixData[0] * (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]) -
			matrixData[1] * (matrixData[3] * matrixData[8] - matrixData[5] * matrixData[6]) +
			matrixData[2] * (matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6]);

	}
	mat3 mat3::inverse() const {
		mat3 rezultat = mat3();
		float det = determinant();
		if (det != std::numeric_limits<float>::epsilon()) {
			float invDet = 1.0f / det;
			mat3 adjoint = mat3();
			(*this).transpose();
			adjoint.matrixData[0] = matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7];
			adjoint.matrixData[1] = -matrixData[1] * matrixData[8] + matrixData[2] * matrixData[7];
			adjoint.matrixData[2] = matrixData[1] * matrixData[5] - matrixData[2] * matrixData[4];
			adjoint.matrixData[3] = -matrixData[3] * matrixData[8] + matrixData[5] * matrixData[6];
			adjoint.matrixData[4] = matrixData[0] * matrixData[8] - matrixData[2] * matrixData[6];
			adjoint.matrixData[5] = -matrixData[0] * matrixData[5] + matrixData[2] * matrixData[3];
			adjoint.matrixData[6] = matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6];
			adjoint.matrixData[7] = -matrixData[0] * matrixData[7] + matrixData[1] * matrixData[6];
			adjoint.matrixData[8] = matrixData[0] * matrixData[4] - matrixData[1] * matrixData[3];

			rezultat = adjoint * invDet;
		}
		return rezultat;
	}
	mat3 mat3::transpose() const {
		mat3 tr;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tr.matrixData[i * 3 + j] = matrixData[j * 3 + i];
			}
		}
		return tr;
	}

}
