#pragma once
#include "Vec3.h"
#include "Ray.h"

class AABB
{
public:
	Vec3 _min;
	Vec3 _max;

	AABB();
	AABB(const Vec3& a, const Vec3& b);
	~AABB();

	Vec3 min() const;
	Vec3 max() const;

	bool Hit(const Ray& r, float tmin, float tmax) const;

	AABB SurroundingBox(AABB box0, AABB box1);
};

