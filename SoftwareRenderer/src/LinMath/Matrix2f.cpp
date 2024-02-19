#include "Matrix2f.hpp"
#include "memory"

Matrix2f::Matrix2f(float val)
{
	memset(data, 0, sizeof(data));
	operator()(1, 1) = val;
	operator()(2, 2) = val;
}

float& Matrix2f::operator()(int i, int k)
{
	return data[i - 1][k - 1];
}

float Matrix2f::operator()(int i, int k) const
{
	return data[i - 1][k - 1];
}

Matrix2f operator*(const Matrix2f& first, const Matrix2f& second)
{
	Matrix2f result;

	result(1, 1) = first(1, 1) * second(1, 1) + first(1, 2) * second(2, 1);
	result(1, 2) = first(1, 1) * second(1, 2) + first(1, 2) * second(2, 2);
	result(2, 1) = first(2, 1) * second(1, 1) + first(2, 2) * second(2, 1);
	result(2, 2) = first(2, 1) * second(1, 2) + first(2, 2) * second(2, 2);

	return result;
}

Vector2f operator*(const Matrix2f& first, const Vector2f& second)
{
	Vector2f result;

	result.x = first(1, 1) * second.x + first(1, 2) * second.y;
	result.y = first(2, 1) * second.x + first(2, 2) * second.y;

	return result;
}

void scale(Matrix2f& mat, const Vector2f scale)
{
	Matrix2f mul;
	mul(1, 1) = scale.x;
	mul(2, 2) = scale.y;
	mat = mat * mul;
}

void rotate(Matrix2f& mat, const float angle)
{
	Matrix2f rot;
	rot(1, 1) = cosf(angle);
	rot(1, 2) = sinf(angle);
	rot(2, 1) = -sinf(angle);
	rot(2, 2) = cosf(angle);
	mat = mat * rot;
}