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