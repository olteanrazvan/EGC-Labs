#include "mat4.h"
#include "mat3.h"
#include <cmath>

namespace egc {
    mat4& mat4::operator =(const mat4& srcMatrix) {
        std::copy(srcMatrix.matrixData, srcMatrix.matrixData + 16, this->matrixData);
        return *this;
    }
    mat4 mat4::operator *(float scalarValue) const {
        mat4 result;
        for (int i = 0; i <= 15; i++) {
            result.matrixData[i] = this->matrixData[i] * scalarValue;
        }

        return result;
    }
    mat4 mat4::operator *(const mat4& srcMatrix) const {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.matrixData[i + 4 * j] = 0;
                for (int k = 0; k < 4; k++) {
                    result.matrixData[i + 4 * j] += this->matrixData[i + 4 * k] * srcMatrix.matrixData[k + 4 * j];
                }
            }
        }

        return result;
    }
    vec4 mat4::operator *(const vec4& srcVector) const {
        vec4 vec;

        vec.x = this->matrixData[0] * srcVector.x + this->matrixData[4] * srcVector.y + this->matrixData[8] * srcVector.z + this->matrixData[12] * srcVector.w;
        vec.y = this->matrixData[1] * srcVector.x + this->matrixData[5] * srcVector.y + this->matrixData[9] * srcVector.z + this->matrixData[13] * srcVector.w;
        vec.z = this->matrixData[2] * srcVector.x + this->matrixData[6] * srcVector.y + this->matrixData[10] * srcVector.z + this->matrixData[14] * srcVector.w;
        vec.w = this->matrixData[3] * srcVector.x + this->matrixData[7] * srcVector.y + this->matrixData[11] * srcVector.z + this->matrixData[15] * srcVector.w;

        return vec;
    }
    mat4 mat4::operator +(const mat4& srcMatrix) const {
        mat4 result;
        for (int i = 0; i <= 15; i++) {
            result.matrixData[i] = this->matrixData[i] + srcMatrix.matrixData[i];
        }

        return result;
    }
    //get element by (row, column)
    float& mat4::at(int i, int j) {
        return this->matrixData[i + 4 * j];
    }
    const float& mat4::at(int i, int j) const {
        return this->matrixData[i + 4 * j];
    }
    float mat4::determinant() const {
        float result = 0;
        for (int k = 0; k < 4; k++) {
            mat3 matrix;
            for (int i = 1; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (k != j) {
                        if (j < k) {
                            matrix.matrixData[i - 1 + 3 * j] = this->matrixData[j + 4 * i];
                        }
                        else {
                            matrix.matrixData[i - 1 + 3 * (j - 1)] = this->matrixData[j + 4 * i];
                        }
                    }
                }
            }

            int sign = k % 2 == 0 ? 1 : -1;
            result += sign * this->matrixData[k] * matrix.determinant();
        }

        return result;
    }

    mat3 newMat3(mat4 mat, int x, int y) {
        mat3 result;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == x)
                    i++;
                if (j == y)
                    j++;
                if (i != x && j != y && i < 4 && j < 4) {
                    int ii = 0, jj = 0;
                    if (i < x)
                        ii = i;
                    else
                        ii = i - 1;

                    if (j < y)
                        jj = j;
                    else
                        jj = j - 1;

                    result.matrixData[ii + jj * 3] = mat.matrixData[i + j * 4];
                }
            }
        }

        result = result.transpose();

        return result;
    }

    mat4 mat4::inverse() const {
        mat4 result;
        mat4 transpose = this->transpose();
        int det = this->determinant();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int sign = (i + j) % 2 == 0 ? 1 : -1;
                mat3 mat = newMat3(transpose, i, j);

                result.matrixData[i + 4 * j] = sign * mat.determinant();
            }
        }

        result = result * (float)(1.0 / det);

        return result;
    }
    mat4 mat4::transpose() const {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.matrixData[i + j * 4] = this->matrixData[i * 4 + j];
            }
        }

        return result;
    }

}