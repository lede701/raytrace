#pragma once
#include "HitRecord.h"
#include "Ray.h"
#include "Vec3.h"

class Materials
{
public:
	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const = 0;
};

