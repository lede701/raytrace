#pragma once
#include "Hitable.h"
#include "Entity.h"
#include "Vec3.h"


class HitList : public Hitable
{
public:
	Entity **eList;
	int eSize;
	Hitable **hList;
	int hSize;

	HitList();
	HitList(Hitable **l, int n);
	HitList(Entity **e, int n);
	~HitList();

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hit) const;

	bool eHit(const Ray& r, float t_min, float t_max, HitRecord& hit) const;
	bool hHit(const Ray& r, float t_min, float t_max, HitRecord& hit) const;
};

