#include "transform.h"

namespace egc {
    mat3 translate(const vec2 translateArray) {
        mat3 auxMatrix = mat3();
        auxMatrix.matrixData[0] = auxMatrix.matrixData[4] = auxMatrix.matrixData[8] = 1;
        auxMatrix.matrixData[6] = translateArray.x;
        auxMatrix.matrixData[7] = translateArray.y;
        return auxMatrix;
    }
    mat3 translate(float tx, float ty) {
        mat3 auxMatrix = mat3();
        auxMatrix.matrixData[0] = auxMatrix.matrixData[4] = auxMatrix.matrixData[8] = 1;
        auxMatrix.matrixData[6] = tx;
        auxMatrix.matrixData[7] = ty;
        return auxMatrix;
    }

    mat3 scale(const vec2 scaleArray) {
        mat3 auxMatrix = mat3();
        auxMatrix.matrixData[0] *= scaleArray.x;
        auxMatrix.matrixData[4] *= scaleArray.y;
        return auxMatrix;
    }
    mat3 scale(float sx, float sy) {
        mat3 auxMatrix = mat3();
        auxMatrix.matrixData[0] *= sx;
        auxMatrix.matrixData[4] *= sy;
        return auxMatrix;
    }

    mat3 rotate(float angle) {
        float radian = PI / 180;
        mat3 auxMatrix = mat3();
        auxMatrix.matrixData[0] = cos(angle * radian);
        auxMatrix.matrixData[1] = sin(angle * radian);
        auxMatrix.matrixData[3] = -sin(angle * radian);
        auxMatrix.matrixData[4] = cos(angle * radian);
        return auxMatrix;
    }

    //transformation matrices in 3D
    mat4 translate(const vec3 translateArray) {
        mat4 auxMatrix = mat4();
        auxMatrix.matrixData[0] = auxMatrix.matrixData[5] = auxMatrix.matrixData[10] = auxMatrix.matrixData[15] = 1;
        auxMatrix.matrixData[12] = translateArray.x;
        auxMatrix.matrixData[13] = translateArray.y;
        auxMatrix.matrixData[14] = translateArray.z;
        return auxMatrix;
    }
    mat4 translate(float tx, float ty, float tz) {
        mat4 auxMatrix = mat4();
        auxMatrix.matrixData[0] = auxMatrix.matrixData[5] = auxMatrix.matrixData[10] = auxMatrix.matrixData[15] = 1;
        auxMatrix.matrixData[12] = tx;
        auxMatrix.matrixData[13] = ty;
        auxMatrix.matrixData[14] = tz;
        return auxMatrix;
    }

    mat4 scale(const vec3 scaleArray) {
        mat4 auxMatrix = mat4();
        auxMatrix.matrixData[0] = scaleArray.x;
        auxMatrix.matrixData[5] = scaleArray.y;
        auxMatrix.matrixData[10] = scaleArray.z;
        auxMatrix.matrixData[15] = 1;
        return auxMatrix;
    }
    mat4 scale(float sx, float sy, float sz) {
        mat4 auxMatrix = mat4();
        auxMatrix.matrixData[0] = sx;
        auxMatrix.matrixData[5] = sy;
        auxMatrix.matrixData[10] = sz;
        auxMatrix.matrixData[15] = 1;
        return auxMatrix;
    }

    mat4 rotateX(float angle) {
        mat4 auxMatrix = mat4();
        const double radian = PI / 180;
        auxMatrix.matrixData[5] = cos(angle * radian);
        auxMatrix.matrixData[9] = -sin(angle * radian);
        auxMatrix.matrixData[6] = sin(angle * radian);
        auxMatrix.matrixData[10] = cos(angle * radian);
        return auxMatrix;
    }
    mat4 rotateY(float angle) {
        mat4 auxMatrix = mat4();
        const double radian = PI / 180;
        auxMatrix.matrixData[0] = cos(angle * radian);
        auxMatrix.matrixData[8] = sin(angle * radian);
        auxMatrix.matrixData[2] = -sin(angle * radian);
        auxMatrix.matrixData[10] = cos(angle * radian);
        return auxMatrix;

    }
    mat4 rotateZ(float angle) {
        mat4 auxMatrix = mat4();
        const double radian = PI / 180;
        auxMatrix.matrixData[0] = cos(angle * radian);
        auxMatrix.matrixData[4] = -sin(angle * radian);
        auxMatrix.matrixData[1] = sin(angle * radian);
        auxMatrix.matrixData[5] = cos(angle * radian);
        return auxMatrix;
    }
}