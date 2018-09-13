#pragma once
#include "Vec3.h"
#include "Entity.h"
#include "AABB.h"

class Sphere: public Entity
{
	AABB _aabb;
public:
	float radius;
	Materials *pMat;

	Sphere();
	Sphere(Vec3 cen, float r, Materials *mat);
	~Sphere();

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const;
	void GetSphereUV(const Vec3& p, float& u, float &v);
	virtual AABB GetAABB() const;
};

