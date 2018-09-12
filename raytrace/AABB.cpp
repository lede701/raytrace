#include "AABB.h"
#include "Utilities.h"


AABB::AABB()
{
}

AABB::AABB(const Vec3& a, const Vec3& b)
{
	// Make sure vectors are in min and max format
	if (a.length() < b.length())
	{
		_min = a;
		_max = b;
	}
	else
	{
		_min = b;
		_max = a;
	}
}

AABB::~AABB()
{
}

Vec3 AABB::min() const
{
	return _min;
}

Vec3 AABB::max() const
{
	return _max;
}

bool AABB::Hit(const Ray& r, float tmin, float tmax) const
{
	bool bRetVal = true;
	for (int i = 0; i < 3; ++i)
	{
		float t0 = ffmin((_min[i] - r.origin()[i]) / r.direction()[i], 
			(_max[i] - r.origin()[i]) / r.direction()[i]);
		float t1 = ffmax((_min[i] - r.origin()[i]) / r.direction()[i], 
			(_max[i] - r.origin()[i]) / r.direction()[i]);

		tmin = ffmax(t0, tmin);
		tmax = ffmin(t1, tmax);

		if (tmax <= tmin) {
			bRetVal = false;
			break;
		}
	}

	return bRetVal;
}

AABB AABB::SurroundingBox(AABB box0, AABB box1)
{
	Vec3 small(fmin(box0.min().x(), box1.min().x()), 
		fmin(box0.min().y(), box1.min().y()),
		fmin(box0.min().z(), box1.min().z()));
	Vec3 big(fmax(box0.max().x(), box1.max().x()),
		fmax(box0.max().y(), box1.max().y()),
		fmax(box0.max().z(), box1.max().z()));

	return AABB(small, big);
}