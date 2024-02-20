#include "Vector.hpp"

#include <cmath>

Vector3f::operator Vector2f() const
{
	return Vector2f{ x, y };
}

Vector3f Vector3f::operator-(const Vector3f vec) const
{
	return Vector3f{x - vec.x, y - vec.y, z - vec.z };
}

Vector3f Vector3f::operator-() const
{
	return Vector3f{ -x, -y, -z };
}

Vector3f Vector3f::operator+(const Vector3f vec) const
{
	return Vector3f{ x + vec.x, y + vec.y, z + vec.z };
}

const Vector3f Vector3f::operator/(const float val) const
{
	Vector3f result = *this;
	result.x /= val;
	result.y /= val;
	result.z /= val;
	return result;
}

Vector3f& Vector3f::operator/=(const float val)
{
	*this = operator/(val);
	return *this;
}

Vector4f::operator Vector2f() const
{
	return Vector2f{ x, y };
}

Vector4f::operator Vector3f() const
{
	return Vector3f{ x, y, z };
}

Vector4f::Vector4f(const float val)
	: x{ val }, y{ val }, z{ val }, w{ 1.0f } {}

Vector4f::Vector4f(const Vector3f& vec)
	: x{ vec.x }, y{ vec.y }, z{ vec.z }, w{ 1.0f } {}

const Vector4f Vector4f::operator/(const float val) const
{
	Vector4f result = *this;
	result.x /= val;
	result.y /= val;
	result.z /= val;
	result.w /= val;
	return result;
}

Vector4f& Vector4f::operator/=(const float val)
{
	*this = operator/(val);
	return *this;
}

Vector3f cross(const Vector3f& first, const Vector3f& second)
{
	return Vector3f
	{
		first.y * second.z - first.z * second.y, 
		first.z * second.x - first.x * second.z, 
		first.x * second.y - first.y * second.x 
	};
}

Vector3f normalize(const Vector3f& vec)
{
	return vec / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}