#include "Matrix4f.hpp"

#include <memory>

Matrix4f::Matrix4f(float val)
{
	memset(data, 0, sizeof(data));
	operator()(1, 1) = val;
	operator()(2, 2) = val;
	operator()(3, 3) = val;
	operator()(4, 4) = val;
}

float& Matrix4f::operator()(int i, int k)
{
	return data[i - 1][k - 1];
}

float Matrix4f::operator()(int i, int k) const
{
	return data[i - 1][k - 1];
}

Matrix4f operator*(const Matrix4f& first, const Matrix4f& second)
{
	Matrix4f result;

	result(1, 1) = first(1, 1) * second(1, 1) + first(1, 2) * second(2, 1) + first(1, 3) * second(3, 1) + first(1, 4) * second(4, 1);
	result(1, 2) = first(1, 1) * second(1, 2) + first(1, 2) * second(2, 2) + first(1, 3) * second(3, 2) + first(1, 4) * second(4, 2);
	result(1, 3) = first(1, 1) * second(1, 3) + first(1, 2) * second(2, 3) + first(1, 3) * second(3, 3) + first(1, 4) * second(4, 3);
	result(1, 4) = first(1, 1) * second(1, 4) + first(1, 2) * second(2, 4) + first(1, 3) * second(3, 4) + first(1, 4) * second(4, 4);

	result(2, 1) = first(2, 1) * second(1, 1) + first(2, 2) * second(2, 1) + first(2, 3) * second(3, 1) + first(2, 4) * second(4, 1);
	result(2, 2) = first(2, 1) * second(1, 2) + first(2, 2) * second(2, 2) + first(2, 3) * second(3, 2) + first(2, 4) * second(4, 2);
	result(2, 3) = first(2, 1) * second(1, 3) + first(2, 2) * second(2, 3) + first(2, 3) * second(3, 3) + first(2, 4) * second(4, 3);
	result(2, 4) = first(2, 1) * second(1, 4) + first(2, 2) * second(2, 4) + first(2, 3) * second(3, 4) + first(2, 4) * second(4, 4);

	result(3, 1) = first(3, 1) * second(1, 1) + first(3, 2) * second(2, 1) + first(3, 3) * second(3, 1) + first(3, 4) * second(4, 1);
	result(3, 2) = first(3, 1) * second(1, 2) + first(3, 2) * second(2, 2) + first(3, 3) * second(3, 2) + first(3, 4) * second(4, 2);
	result(3, 3) = first(3, 1) * second(1, 3) + first(3, 2) * second(2, 3) + first(3, 3) * second(3, 3) + first(3, 4) * second(4, 3);
	result(3, 4) = first(3, 1) * second(1, 4) + first(3, 2) * second(2, 4) + first(3, 3) * second(3, 4) + first(3, 4) * second(4, 4);

	result(4, 1) = first(3, 1) * second(1, 1) + first(4, 2) * second(2, 1) + first(4, 3) * second(3, 1) + first(4, 4) * second(4, 1);
	result(4, 2) = first(3, 1) * second(1, 2) + first(4, 2) * second(2, 2) + first(4, 3) * second(3, 2) + first(4, 4) * second(4, 2);
	result(4, 3) = first(3, 1) * second(1, 3) + first(4, 2) * second(2, 3) + first(4, 3) * second(3, 3) + first(4, 4) * second(4, 3);
	result(4, 4) = first(3, 1) * second(1, 4) + first(4, 2) * second(2, 4) + first(4, 3) * second(3, 4) + first(4, 4) * second(4, 4);

	return result;
}

Vector4f operator*(const Matrix4f& first, const Vector4f& second)
{
	Vector4f result;

	result.x = first(1, 1) * second.x + first(1, 2) * second.y + first(1, 3) * second.z + first(1, 4) * second.w;
	result.y = first(2, 1) * second.x + first(2, 2) * second.y + first(2, 3) * second.z + first(2, 4) * second.w;
	result.z = first(3, 1) * second.x + first(3, 2) * second.y + first(3, 3) * second.z + first(3, 4) * second.w;
	result.w = first(3, 1) * second.x + first(4, 2) * second.y + first(4, 3) * second.z + first(4, 4) * second.w;

	return result;
}

void scale(Matrix4f& mat, const Vector3f& scale)
{
	Matrix4f mul;
	mul(1, 1) = scale.x;
	mul(2, 2) = scale.y;
	mul(3, 3) = scale.z;
	mat = mat * mul;
}

void rotateX(Matrix4f& mat, const float angle)
{
	Matrix4f rot;
	rot(2, 2) = cosf(angle);
	rot(2, 3) = sinf(angle);
	rot(3, 2) = -sinf(angle);
	rot(3, 3) = cosf(angle);
	mat = mat * rot;
}

void rotateY(Matrix4f& mat, const float angle)
{
	Matrix4f rot;
	rot(1, 1) = cosf(angle);
	rot(1, 3) = sinf(angle);
	rot(3, 1) = -sinf(angle);
	rot(3, 3) = cosf(angle);
	mat = mat * rot;
}

void rotateZ(Matrix4f& mat, const float angle)
{
	Matrix4f rot;
	rot(1, 1) = cosf(angle);
	rot(1, 2) = sinf(angle);
	rot(2, 1) = -sinf(angle);
	rot(2, 2) = cosf(angle);
	mat = mat * rot;
}

void translate(Matrix4f& mat, const Vector3f& vec)
{
	Matrix4f trans;
	trans(1, 4) = vec.x;
	trans(2, 4) = vec.y;
	trans(3, 4) = vec.z;
	mat = mat * trans;
}

Matrix4f perspective(const float fovy, const float aspect, const float n, const float f)
{
	Matrix4f mat;
	mat(1, 1) = 1.0f / (aspect * tan(fovy / 2));
	mat(2, 2) = 1.0f / tan(fovy / 2);
	mat(3, 3) = -(f + n) / (f - n);
	mat(3, 4) = -1.0f;
	mat(4, 3) = -(2 * f * n) / (f - n);
	mat(4, 4) = 0.0f;
	return mat;
}

Matrix4f lookAt(const Vector3f& eye, const Vector3f& forward, const Vector3f& right, const Vector3f& up)
{
	Matrix4f view;
	view(1, 1) = right.x;	view(1, 2) = right.y;	view(1, 3) = right.z;
	view(2, 1) = up.x;		view(2, 2) = up.y;		view(2, 3) = up.z;
	view(3, 1) = forward.x;	view(3, 2) = forward.y;	view(3, 3) = forward.z;
	translate(view, -eye);
	return view;
}