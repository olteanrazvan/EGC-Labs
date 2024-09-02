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
        return vec4(x + srcVector.x, y + srcVector.y, z + srcVector.z,w + srcVector.w);
    }
    vec4& vec4::operator +=(const vec4& srcVector) {
        x += srcVector.x;
        y += srcVector.y;
        z += srcVector.z;
        w += srcVector.w;
        return *this;
    }
    vec4 vec4::operator *(float scalarValue) const {
        return vec4(x * scalarValue, y * scalarValue, z * scalarValue,w * scalarValue);
    }
    vec4 vec4::operator -(const vec4& srcVector) const {
        return vec4(x - srcVector.x, y - srcVector.y, z - srcVector.z,w - srcVector.w);
    }
    vec4& vec4::operator -=(const vec4& srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;
        z -= srcVector.z;
        w -= srcVector.w;
        return *this;
    }
    vec4 vec4::operator -() const {
        return vec4(-x, -y, -z, -w);
    }
    float vec4::length() const {
        return sqrt(x * x + y * y + z * z + w * w);
    }
    vec4& vec4::normalize() {
        float l = length();
        if (l > std::numeric_limits<float>::epsilon()) {
            x /= l;
            y /= l;
            z /= l;
            w /= l;
        }
        return *this;
    }
}