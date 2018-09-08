#pragma once
#include "Materials.h"
#include "Texture.h"
#include "Vec3.h"

class Lambertian : public Materials
{
public:
	Texture* albedo;
	Lambertian(Texture* texture);
	~Lambertian();

	virtual bool Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const;
};

