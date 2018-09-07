#pragma once
#include "Vec3.h"
#include "Entity.h"

class Sphere: public Entity
{
public:
	float radius;
	Materials *pMat;

	Sphere();
	Sphere(Vec3 cen, float r, Materials *mat);
	~Sphere();

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const;
};
