#pragma once
#include "Ray.h"
#include "HitRecord.h"

class Hitable
{
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const = 0;
};

