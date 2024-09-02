#include "mat4.h"

namespace egc {
	mat4& mat4::operator =(const mat4& srcMatrix) {
		for (int i = 0; i < 16; i++) {
			matrixData[i] = srcMatrix.matrixData[i];
		}
		return *this;
	}
	mat4 mat4::operator *(float scalarValue) const {
		mat4 res;
		for (int i = 0; i < 16; i++) {
			res.matrixData[i] = scalarValue * matrixData[i];
		}
		return res;
	}
	mat4 mat4::operator *(const mat4& srcMatrix) const {
		mat4 res;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				float sum = 0;
				for (int k = 0; k < 4; k++) {
					sum += matrixData[i * 4 + k] * srcMatrix.matrixData[k * 4 + j];
				}
				res.matrixData[i + 4 * j] = sum;
			}

		}
		return res;
	}
	vec4 mat4::operator *(const vec4& srcVector) const {
		vec4 res;
		res.x = matrixData[0] * srcVector.x + matrixData[4] * srcVector.y + matrixData[8] * srcVector.z +matrixData[12] * srcVector.w;
		res.y = matrixData[1] * srcVector.x + matrixData[5] * srcVector.y + matrixData[9] * srcVector.z + matrixData[13] * srcVector.w;
		res.z = matrixData[2] * srcVector.x + matrixData[6] * srcVector.y + matrixData[10] * srcVector.z + matrixData[14] * srcVector.w;
		res.w = matrixData[3] * srcVector.x + matrixData[7] * srcVector.y + matrixData[11] * srcVector.z + matrixData[15] * srcVector.w;

		return res;
	}
	mat4  mat4::operator + (const mat4 & srcMatrix) const {
		mat4 res;
		for (int i = 0; i < 16; i++) {
			res.matrixData[i] = srcMatrix.matrixData[i] + matrixData[i];
		}
		return res;
	}
	//get element by (row, column)
	float& mat4::at(int i, int j) {
		return matrixData[i + 4 * j];
	}
	const float& mat4::at(int i, int j) const {
		return matrixData[i + 4 * j];
	}
	float mat4::determinant() const {
		float res = 0.0f;
		return res;
	}
	mat4 mat4::inverse() const {
		mat4 res;
		return res;
	}
	mat4 mat4::transpose() const {
		mat4 tr;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tr.matrixData[i * 4 + j] = matrixData[j * 4 + i];
			}
		}
		return tr;
	}
}


