#include "transform.h"
#include "math.h"
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include "mat4.h"

namespace egc {

    
    mat3 translate(const vec2 translateArray) {
        mat3 result = mat3();
        result.matrixData[6] = translateArray.x;
        result.matrixData[7] = translateArray.y;
        return result;
    }
    mat3 translate(float tx, float ty) {
        mat3 result = mat3();
        result.matrixData[6] = tx;
        result.matrixData[7] = ty;
        return result;
    }

    mat3 scale(const vec2 scaleArray) {
        mat3 result = mat3();
        result.matrixData[0] = scaleArray.x;
        result.matrixData[4] = scaleArray.y;
        return result;
    }
    mat3 scale(float sx, float sy) {
        mat3 result = mat3();
        result.matrixData[0] = sx;
        result.matrixData[4] = sy;
        return result;
    }

    mat3 rotate(float angle) {
        float rad = (angle * PI) / 180.0f;
        mat3 result = mat3();
        result.matrixData[0] = cos(rad);
        result.matrixData[1] = sin(rad);
        result.matrixData[3] = -sin(rad);
        result.matrixData[4] = cos(rad);
        return result;
        
    }


    mat4 translate(const vec3 translateArray) {
        mat4 mat = mat4();
        mat.matrixData[12] = translateArray.x;
        mat.matrixData[13] = translateArray.y;
        mat.matrixData[14] = translateArray.z;
        return mat;
    }
    mat4 translate(float tx, float ty, float tz) {
        mat4 mat = mat4();
        mat.matrixData[12] = tx;
        mat.matrixData[13] = ty;
        mat.matrixData[14] = tz;
        return mat;
    }

    mat4 scale(const vec3 scaleArray) {
        mat4 mat = mat4();
        mat.matrixData[0] = scaleArray.x;
        mat.matrixData[5] = scaleArray.y;
        mat.matrixData[10] = scaleArray.z;
        return mat;

    }
    mat4 scale(float sx, float sy, float sz) {
        mat4 mat = mat4();
        mat.matrixData[0] = sx;
        mat.matrixData[5] = sy;
        mat.matrixData[10] = sz;
        return mat;
    }

    mat4 rotateX(float angle) {
        mat4 mat = mat4();
        const double factor = PI / 180;
        mat.matrixData[5] = cos(angle * factor);
        mat.matrixData[9] = -sin(angle * factor);
        mat.matrixData[6] = sin(angle * factor);
        mat.matrixData[10] = cos(angle * factor);
        return mat;
    }

    mat4 rotateY(float angle) {
        mat4 mat = mat4();
        const double factor = PI / 180;
        mat.matrixData[0] = cos(angle * factor);
        mat.matrixData[8] = sin(angle * factor);
        mat.matrixData[2] = -sin(angle * factor);
        mat.matrixData[10] = cos(angle * factor);
        return mat;
    }

    mat4 rotateZ(float angle) {
        mat4 mat = mat4();
        const double factor = PI / 180;
        mat.matrixData[0] = cos(angle * factor);
        mat.matrixData[4] = -sin(angle * factor);
        mat.matrixData[1] = sin(angle * factor);
        mat.matrixData[5] = cos(angle * factor);
        return mat;
    }
} 
