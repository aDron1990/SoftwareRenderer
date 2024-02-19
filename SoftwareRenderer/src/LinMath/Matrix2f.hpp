#pragma once

#include "Vector.hpp"

struct Matrix2f
{
	Matrix2f(float val = 1.0f);

	float data[2][2];
	float& operator()(int i, int k);
	float operator()(int i, int k) const;
};

Matrix2f operator*(const Matrix2f& first, const Matrix2f& second);
Vector2f operator*(const Matrix2f& first, const Vector2f& second);

void scale(Matrix2f& mat, const Vector2f scale);
void rotate(Matrix2f& mat, const float angle);

