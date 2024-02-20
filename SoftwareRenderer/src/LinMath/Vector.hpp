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
};

struct Vector4f
{
	float x;
	float y;
	float z;
	float w;

	operator Vector2f() const;
	operator Vector3f() const;
	Vector4f(const float val = 0.0f);
	Vector4f(const Vector3f& vec);

};