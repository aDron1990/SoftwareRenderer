#pragma once

struct Vector2i
{
	int x;
	int y;
};

struct Vector2f
{
	float x;
	float y;
};

struct Vector3f
{
	float x;
	float y;
	float z;

	operator Vector2f() const;
	Vector3f operator-(const Vector3f vec) const;
	Vector3f operator+(const Vector3f vec) const;
	Vector3f operator-() const;
	const Vector3f operator/(const float val) const;
	Vector3f& operator/=(const float val);

};

struct Vector4f
{
	float x;
	float y;
	float z;
	float w;

	operator Vector2f() const;
	operator Vector3f() const;
	const Vector4f operator/(const float val) const;
	Vector4f& operator/=(const float val);

	Vector4f(const float val = 0.0f);
	Vector4f(const Vector3f& vec);

};

Vector3f cross(const Vector3f& first, const Vector3f& second);
Vector3f normalize(const Vector3f& vec);