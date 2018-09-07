#pragma once
#include "Materials.h"
#include "Vec3.h"

class Lambertian : public Materials
{
public:
	Vec3 albedo;
	Lambertian(const Vec3& a);
	~Lambertian();

	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const;
};

