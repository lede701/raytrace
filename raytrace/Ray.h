#pragma once

#include "Vec3.h"

class Ray
{
public:
	Vec3 A;
	Vec3 B;

	Ray();
	Ray(const Vec3& a, const Vec3& b);
	~Ray();

	Vec3 origin() const;
	Vec3 direction() const;
	Vec3 point_at_parameter(float t) const;
};

