#include "Matrix3f.hpp"
#include "memory"

Matrix3f::Matrix3f(float val)
{
	memset(data, 0, sizeof(data));
	operator()(1, 1) = val;
	operator()(2, 2) = val;
	operator()(3, 3) = val;
}

float& Matrix3f::operator()(int i, int k)
{
	return data[i - 1][k - 1];
}

float Matrix3f::operator()(int i, int k) const
{
	return data[i - 1][k - 1];
}

Matrix3f operator*(const Matrix3f& first, const Matrix3f& second)
{
	Matrix3f result;

	result(1, 1) = first(1, 1) * second(1, 1) + first(1, 2) * second(2, 1) + first(1, 3) * second(3, 1);
	result(1, 2) = first(1, 1) * second(1, 2) + first(1, 2) * second(2, 2) + first(1, 3) * second(3, 2);
	result(1, 3) = first(1, 1) * second(1, 3) + first(1, 2) * second(2, 3) + first(1, 3) * second(3, 3);

	result(2, 1) = first(2, 1) * second(1, 1) + first(2, 2) * second(2, 1) + first(2, 3) * second(3, 1);
	result(2, 2) = first(2, 1) * second(1, 2) + first(2, 2) * second(2, 2) + first(2, 3) * second(3, 2);
	result(2, 3) = first(2, 1) * second(1, 3) + first(2, 2) * second(2, 3) + first(2, 3) * second(3, 3);

	result(3, 1) = first(3, 1) * second(1, 1) + first(3, 2) * second(2, 1) + first(3, 3) * second(3, 1);
	result(3, 2) = first(3, 1) * second(1, 2) + first(3, 2) * second(2, 2) + first(3, 3) * second(3, 2);
	result(3, 3) = first(3, 1) * second(1, 3) + first(3, 2) * second(2, 3) + first(3, 3) * second(3, 3);

	return result;
}

Vector3f operator*(const Matrix3f& first, const Vector3f& second)
{
	Vector3f result;

	result.x = first(1, 1) * second.x + first(1, 2) * second.y + first(1, 3) * second.z;
	result.y = first(2, 1) * second.x + first(2, 2) * second.y + first(2, 3) * second.z;
	result.z = first(3, 1) * second.x + first(3, 2) * second.y + first(3, 3) * second.z;

	return result;
}

void scale(Matrix3f& mat, const Vector3f scale)
{
	Matrix3f mul;
	mul(1, 1) = scale.x;
	mul(2, 2) = scale.y;
	mul(3, 3) = scale.z;
	mat = mat * mul;
}

void rotateX(Matrix3f& mat, const float angle)
{
	Matrix3f rot;
	rot(2, 2) = cosf(angle);
	rot(2, 3) = sinf(angle);
	rot(3, 2) = -sinf(angle);
	rot(3, 3) = cosf(angle);
	mat = mat * rot;
}

void rotateY(Matrix3f& mat, const float angle)
{
	Matrix3f rot;
	rot(1, 1) = cosf(angle);
	rot(1, 3) = sinf(angle);
	rot(3, 1) = -sinf(angle);
	rot(3, 3) = cosf(angle);
	mat = mat * rot;
}

void rotateZ(Matrix3f& mat, const float angle)
{
	Matrix3f rot;
	rot(1, 1) = cosf(angle);
	rot(1, 2) = sinf(angle);
	rot(2, 1) = -sinf(angle);
	rot(2, 2) = cosf(angle);
	mat = mat * rot;
}