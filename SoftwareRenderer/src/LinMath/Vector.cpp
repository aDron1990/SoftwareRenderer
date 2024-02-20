#include "Vector.hpp"

Vector3f::operator Vector2f() const
{
	return Vector2f{ x, y };
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