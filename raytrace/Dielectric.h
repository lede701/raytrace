#pragma once
#include "Materials.h"

class Dielectric : public Materials
{
public:
	float refIdx;

	Dielectric(float idx);
	~Dielectric();

	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const;
};

