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
		return vec4(x + srcVector.x, y + srcVector.y, z + srcVector.z, w + srcVector.w);
	}

	vec4& vec4::operator +=(const vec4& srcVector) {
		x = x + srcVector.x;
		y = y + srcVector.y;
		z = z + srcVector.z;
		w = w + srcVector.w;
		return *this;

	}


	vec4 vec4::operator *(float scalarValue) const {
		return vec4(x * scalarValue, y * scalarValue, z * scalarValue, w * scalarValue);

	}


	vec4 vec4::operator -(const vec4& srcVector) const {
		return vec4(x - srcVector.x, y - srcVector.y, z - srcVector.z, w - srcVector.w);
	}


	vec4& vec4::operator -=(const vec4& srcVector) {
		x = x - srcVector.x;
		y = y - srcVector.y;
		z = z - srcVector.z;
		w = w - srcVector.w;
		return *this;
	}


	vec4 vec4::operator -() const {
		return vec4(-x, -y, -z, -w);

	}
	float  vec4::length() const {
		return sqrt(x * x + y * y + z * z + w*w);


	}
	vec4& vec4::normalize() {
		float len = length();
		if (len > std::numeric_limits<float>::epsilon()) {
			x = x / len;
			y = y / len;
			z = z / len;
			w = w / len;
		}
		return *this;
	}
}
