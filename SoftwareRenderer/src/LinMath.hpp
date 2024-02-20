#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
static const float PI = atan(1) * 4;
inline float toRadians(float degrees)
{
	return degrees * (PI / 180);
}

#include "LinMath/Vector.hpp"
#include "LinMath/Matrix2f.hpp"
#include "LinMath/Matrix3f.hpp"
#include "LinMath/Matrix4f.hpp"