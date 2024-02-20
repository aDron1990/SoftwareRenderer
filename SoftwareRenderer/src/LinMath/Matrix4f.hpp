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