#pragma once
#include "Materials.h"

class Metal : public Materials
{
public:
	Vec3 albedo;
	float fuzz;

	Metal(const Vec3& a, float f);
	~Metal();

	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const;
};

