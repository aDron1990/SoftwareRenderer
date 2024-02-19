#pragma once

#include "Vector.hpp"

struct Matrix3f
{
	Matrix3f(float val = 1.0f);

	float data[3][3];
	float& operator()(int i, int k);
	float operator()(int i, int k) const;
};

Matrix3f operator*(const Matrix3f& first, const Matrix3f& second);
Vector3f operator*(const Matrix3f& first, const Vector3f& second);

void scale(Matrix3f& mat, const Vector3f scale);
void rotateX(Matrix3f& mat, const float angle);
void rotateY(Matrix3f& mat, const float angle);
void rotateZ(Matrix3f& mat, const float angle);