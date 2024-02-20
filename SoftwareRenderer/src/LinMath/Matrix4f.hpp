#pragma once

#include "Vector.hpp"

struct Matrix4f
{
	Matrix4f(float val = 1.0f);

	float data[4][4];
	float& operator()(int i, int k);
	float operator()(int i, int k) const;
};

Matrix4f operator*(const Matrix4f& first, const Matrix4f& second);
Vector4f operator*(const Matrix4f& first, const Vector4f& second);

void scale(Matrix4f& mat, const Vector3f& scale);
void rotateX(Matrix4f& mat, const float angle);
void rotateY(Matrix4f& mat, const float angle);
void rotateZ(Matrix4f& mat, const float angle);
void translate(Matrix4f& mat, const Vector3f& trans);

Matrix4f perspective(const float fovy, const float aspect, const float n = 1.0f, const float f = 100.0f);
Matrix4f lookAt(const Vector3f& eye, const Vector3f& forward, const Vector3f& right, const Vector3f& up);