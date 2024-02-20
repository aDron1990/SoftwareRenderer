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