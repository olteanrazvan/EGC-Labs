#include "mat4.h"

namespace egc {
    mat4& mat4::operator =(const mat4& srcMatrix) {
        for (int i = 0; i < 16; i++) {
            matrixData[i] = srcMatrix.matrixData[i];
        }
        return *this;
    }
    mat4 mat4::operator *(float scalarValue) const {
        float auxMatrix[9];
        for (int i = 0; i < 16; i++) {
            auxMatrix[i] = scalarValue * matrixData[i];
        }
        return mat4(auxMatrix);
    }
    mat4 mat4::operator *(const mat4& srcMatrix) const {
        float auxMatrix[16];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    auxMatrix[i + 4 * j] += matrixData[i + 4 * k] * srcMatrix.matrixData[k + 4 * j];
                }
            }
        }
        return mat4(auxMatrix);
    }
    vec4 mat4::operator *(const vec4& srcVector) const {
        return vec4(matrixData[0] * srcVector.x + matrixData[4] * srcVector.y + matrixData[8] * srcVector.z + matrixData[12] * srcVector.w,
                    matrixData[1] * srcVector.x + matrixData[5] * srcVector.y + matrixData[9] * srcVector.z + matrixData[13] * srcVector.w,
                    matrixData[2] * srcVector.x + matrixData[6] * srcVector.y + matrixData[10] * srcVector.z + matrixData[14] * srcVector.w,
                    matrixData[3] * srcVector.x + matrixData[7] * srcVector.y + matrixData[11] * srcVector.z + matrixData[15] * srcVector.w);
    }
    mat4 mat4::operator +(const mat4& srcMatrix) const {
        float newMatrixData[16];
        for (int i = 0; i < 16; i++)
            newMatrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
        return mat4(newMatrixData);
    }
    float& mat4::at(int i, int j) {
        return matrixData[4 * j + i];
    }
    const float& mat4::at(int i, int j) const {
        return matrixData[4 * j + i];
    }
    float mat4::determinant() const {
        float det = 0.0;
        mat4 tmp(*this);
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                float factor = tmp.matrixData[j * 4 + i] / tmp.matrixData[i * 4 + i];
                for (int k = i; k < 4; ++k) {
                    tmp.matrixData[j * 4 + k] -= tmp.matrixData[i * 4 + k] * factor;
                }
            }
        }
        det = tmp.matrixData[0] * tmp.matrixData[5] * tmp.matrixData[10] * tmp.matrixData[15];

        return det;
    }
    mat4 mat4::inverse() const {
        mat4 rezultat;
        mat4 tmp(*this);

        for (int i = 0; i < 4; ++i) {
            float pivot = tmp.matrixData[i * 4 + i];
            for (int j = 0; j < 4; ++j) {
                tmp.matrixData[i * 4 + j] /= pivot;
                rezultat.matrixData[i * 4 + j] /= pivot;
            }
            for (int k = 0; k < 4; ++k) {
                if (k == i)
                    continue;
                float factor = tmp.matrixData[k * 4 + i];
                for (int l = 0; l < 4; ++l) {
                    tmp.matrixData[k * 4 + l] -= tmp.matrixData[i * 4 + l] * factor;
                    rezultat.matrixData[k * 4 + l] -= rezultat.matrixData[i * 4 + l] * factor;
                }
            }
        }

        return rezultat;
    }
    mat4 mat4::transpose() const {
        mat4 rezultat;

        rezultat.matrixData[0] = matrixData[0];
        rezultat.matrixData[4] = matrixData[1];
        rezultat.matrixData[8] = matrixData[2];
        rezultat.matrixData[12] = matrixData[3];
        rezultat.matrixData[1] = matrixData[4];
        rezultat.matrixData[5] = matrixData[5];
        rezultat.matrixData[9] = matrixData[6];
        rezultat.matrixData[13] = matrixData[7];
        rezultat.matrixData[2] = matrixData[8];
        rezultat.matrixData[6] = matrixData[9];
        rezultat.matrixData[10] = matrixData[10];
        rezultat.matrixData[14] = matrixData[11];
        rezultat.matrixData[3] = matrixData[12];
        rezultat.matrixData[7] = matrixData[13];
        rezultat.matrixData[11] = matrixData[14];
        rezultat.matrixData[15] = matrixData[15];

        return rezultat;
    }
}