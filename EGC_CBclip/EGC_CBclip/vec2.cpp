#include "vec2.h"

namespace egc {
    vec2& vec2::operator =(const vec2& srcVector) {
        x = srcVector.x;
        y = srcVector.y;
        return *this;
    }
    vec2 vec2::operator +(const vec2& srcVector) const {
        return vec2(x + srcVector.x, y + srcVector.y);
    }
    vec2& vec2::operator +=(const vec2& srcVector) {
        x += srcVector.x;
        y += srcVector.y;
        return *this;
    }
    vec2 vec2::operator *(float scalarValue) const {
        return vec2(x * scalarValue,y * scalarValue);
    }
    vec2 vec2::operator -(const vec2& srcVector) const {
        return vec2(x - srcVector.x, y - srcVector.y);
    }
    vec2& vec2::operator -=(const vec2& srcVector) {
        x -= srcVector.x;
        y -= srcVector.y;
        return *this;
    }
    vec2 vec2::operator -() const {
        return vec2(-x, -y);
    }
    float vec2::length() const {
        return sqrt(x * x + y * y);
    }
    vec2& vec2::normalize() {
        float l = length();
        if (l > std::numeric_limits<float>::epsilon()) {
            x /= l;
            y /= l;
        }
        return *this;
    }
    float dotProduct(const vec2& v1, const vec2& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }
}