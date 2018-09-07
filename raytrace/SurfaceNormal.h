#pragma once
#include "Materials.h"
#include "Vec3.h"

class SurfaceNormal : public Materials
{
public:
	Vec3 albedo;
	SurfaceNormal(Vec3 a);
	~SurfaceNormal();

	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const; 
};

