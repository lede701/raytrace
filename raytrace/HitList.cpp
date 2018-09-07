#include "HitList.h"



HitList::HitList()
{
}

HitList::HitList(Hitable **l, int n) 
{
	hList = l;
	hSize = n;
	eSize = -1;
}

HitList::HitList(Entity **e, int n)
{
	eList = e;
	eSize = n;
	hSize = -1;
}

HitList::~HitList()
{
}

bool HitList::hit(const Ray& r, float t_min, float t_max, HitRecord& hit) const
{
	bool bRetVal = false;
	if (eSize > 0)
	{
		bRetVal = eHit(r, t_min, t_max, hit);
	}
	else if (hSize > 0)
	{
		bRetVal = hHit(r, t_min, t_max, hit);
	}
	return bRetVal;
}

bool HitList::eHit(const Ray& r, float t_min, float t_max, HitRecord& hit) const
{
	HitRecord temp_hit;
	bool hitAnything = false;

	float closestSoFar = t_max;
	for (int i = 0; i < eSize; ++i)
	{
		if (eList[i]->hit(r, t_min, closestSoFar, temp_hit))
		{
			hitAnything = true;
			closestSoFar = temp_hit.t;
			hit = temp_hit;
		}
	}
	return hitAnything;
}

bool HitList::hHit(const Ray& r, float t_min, float t_max, HitRecord& hit) const
{
	HitRecord temp_hit;
	bool hitAnything = false;

	float closestSoFar = t_max;
	for (int i = 0; i < hSize; ++i)
	{
		if (hList[i]->hit(r, t_min, closestSoFar, temp_hit))
		{
			hitAnything = true;
			closestSoFar = temp_hit.t;
			hit = temp_hit;
		}
	}
	return hitAnything;
}

