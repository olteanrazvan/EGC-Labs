#include "vec3.h"

namespace egc {
	vec3& vec3::operator =(const vec3& srcVector) {

		x = srcVector.x;
		y = srcVector.y;
		z = srcVector.z;
		return *this;
	}


	vec3 vec3::operator +(const vec3& srcVector) const {
		return vec3(x + srcVector.x, y + srcVector.y, z + srcVector.z);
	}


	float dotProduct(const vec3& v1, const vec3& v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	vec3 crossProduct(const vec3& v1, const vec3& v2) {
		return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x * v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	vec3& vec3::operator +=(const vec3& srcVector) {
		x = x + srcVector.x;
		y = y + srcVector.y;
		z = z + srcVector.z;
		return *this;

	}


	vec3 vec3::operator *(float scalarValue) const {
		return vec3(x * scalarValue, y * scalarValue, z * scalarValue);

	}


	vec3 vec3::operator -(const vec3& srcVector) const {
		return vec3(x - srcVector.x, y - srcVector.y, z - srcVector.z);
	}


	vec3& vec3::operator -=(const vec3& srcVector) {
		x = x - srcVector.x;
		y = y - srcVector.y;
		z = z - srcVector.z;
		return *this;
	}


	vec3 vec3::operator -() const {
		return vec3(-x, -y, -z);

	}
	float  vec3::length() const {
		return sqrt(x * x + y * y + z * z);


	}
	vec3& vec3::normalize() {
		float len = length();
		if (len > std::numeric_limits<float>::epsilon()) {
			x = x / len;
			y = y / len;
			z = z / len;
		}
		return *this;
	}
}
