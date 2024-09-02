#include "vec4.h"

namespace egc {
    vec4& vec4::operator =(const vec4& srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        z = srcVector.z;
        w = srcVector.w;
        return *this;
    }
    vec4 vec4::operator +(const vec4& srcVector) const {
        vec4 v;

        v.x = this->x + srcVector.x;
        v.y = this->y + srcVector.y;
        v.z = this->z + srcVector.z;
        v.w = this->w + srcVector.w;
        return v;
    }
    vec4& vec4::operator +=(const vec4& srcVector) {
        this->x += srcVector.x;
        this->y += srcVector.y;
        this->z += srcVector.z;
        this->w += srcVector.w;
        return *this;
    }
    vec4 vec4::operator *(float scalarValue) const {
        vec4 v;

        v.x = this->x * scalarValue;
        v.y = this->y * scalarValue;
        v.z = this->z * scalarValue;
        v.w = this->w * scalarValue;
        return v;
    }
    vec4 vec4::operator -(const vec4& srcVector) const {
        vec4 v;

        v.x = this->x - srcVector.x;
        v.y = this->y - srcVector.y;
        v.z = this->z - srcVector.z;
        v.w = this->w - srcVector.w;
        return v;
    }
    vec4& vec4::operator -=(const vec4& srcVector) {
        this->x -= srcVector.x;
        this->y -= srcVector.y;
        this->z -= srcVector.z;
        this->w -= srcVector.w;
        return *this;
    }
    vec4 vec4::operator -() const {
        vec4 v;

        v.x = -this->x;
        v.y = -this->y;
        v.z = -this->z;
        v.w = -this->w;
        return v;
    }
    float vec4::length() const {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }
    vec4& vec4::normalize() {
        float len = this->length();

        this->x = this->x / len;
        this->y = this->y / len;
        this->z = this->z / len;
        this->w = this->w / len;
        return *this;
    }
}