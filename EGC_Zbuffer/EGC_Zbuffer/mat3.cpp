#include "mat3.h"
#include <cmath>

namespace egc {
    mat3& mat3::operator =(const mat3& srcMatrix) {
        std::copy(srcMatrix.matrixData, srcMatrix.matrixData + 9, this->matrixData);
        return *this;
    }
    mat3 mat3::operator *(float scalarValue) const {
        mat3 result;

        for (int i = 0; i < 9; i++) {
            result.matrixData[i] = this->matrixData[i] * scalarValue;
        }

        return result;
    }
    mat3 mat3::operator *(const mat3& srcMatrix) const {
        mat3 result;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.matrixData[i + j * 3] = 0;
                for (int k = 0; k < 3; k++) {
                    result.matrixData[i + j * 3] += this->matrixData[i + k * 3] * srcMatrix.matrixData[j * 3 + k];
                }
            }
        }

        return result;
    }
    vec3 mat3::operator *(const vec3& srcVector) const {
        vec3 vec;
        vec.x = this->matrixData[0] * srcVector.x + this->matrixData[3] * srcVector.y + this->matrixData[6] * srcVector.z;
        vec.y = this->matrixData[1] * srcVector.x + this->matrixData[4] * srcVector.y + this->matrixData[7] * srcVector.z;
        vec.z = this->matrixData[2] * srcVector.x + this->matrixData[5] * srcVector.y + this->matrixData[8] * srcVector.z;

        return vec;
    }
    mat3 mat3::operator +(const mat3& srcMatrix) const {
        mat3 result;

        for (int i = 0; i < 9; i++) {
            result.matrixData[i] = this->matrixData[i] + srcMatrix.matrixData[i];
        }

        return result;
    }
    //get element by (row, column)
    float& mat3::at(int i, int j) {
        return matrixData[i * 3 + j];
    }
    const float& mat3::at(int i, int j) const {
        return matrixData[i * 3 + j];
    }
    float mat3::determinant() const {
        float det = 0;

        det = this->at(0, 0) * this->at(1, 1) * this->at(2, 2) +
            this->at(1, 0) * this->at(2, 1) * this->at(0, 2) +
            this->at(0, 1) * this->at(1, 2) * this->at(2, 0) -
            this->at(0, 2) * this->at(1, 1) * this->at(2, 0) -
            this->at(0, 0) * this->at(2, 1) * this->at(1, 2) -
            this->at(2, 2) * this->at(1, 0) * this->at(0, 1);

        return det;
    }
    mat3 mat3::inverse() const {
        mat3 result;
        mat3 transpose = this->transpose();
        int det = this->determinant();

        if (det == 0)
            return NULL;

        result.matrixData[0] = (+1) * (transpose.matrixData[4] * transpose.matrixData[8] - transpose.matrixData[5] * transpose.matrixData[7]);
        result.matrixData[1] = (-1) * (transpose.matrixData[3] * transpose.matrixData[8] - transpose.matrixData[5] * transpose.matrixData[6]);
        result.matrixData[2] = (+1) * (transpose.matrixData[3] * transpose.matrixData[7] - transpose.matrixData[4] * transpose.matrixData[6]);
        result.matrixData[3] = (-1) * (transpose.matrixData[1] * transpose.matrixData[8] - transpose.matrixData[2] * transpose.matrixData[7]);
        result.matrixData[4] = (+1) * (transpose.matrixData[0] * transpose.matrixData[8] - transpose.matrixData[2] * transpose.matrixData[6]);
        result.matrixData[5] = (-1) * (transpose.matrixData[0] * transpose.matrixData[7] - transpose.matrixData[1] * transpose.matrixData[6]);
        result.matrixData[6] = (+1) * (transpose.matrixData[1] * transpose.matrixData[5] - transpose.matrixData[2] * transpose.matrixData[4]);
        result.matrixData[7] = (-1) * (transpose.matrixData[0] * transpose.matrixData[5] - transpose.matrixData[2] * transpose.matrixData[3]);
        result.matrixData[8] = (+1) * (transpose.matrixData[0] * transpose.matrixData[4] - transpose.matrixData[1] * transpose.matrixData[3]);

        result = result * (float)(1.0 / det);

        return result;
    }
    mat3 mat3::transpose() const {
        mat3 result;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.matrixData[i + j * 3] = this->matrixData[j + i * 3];
            }
        }

        return result;
    }
}