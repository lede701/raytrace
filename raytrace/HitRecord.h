#pragma once
#include "Vec3.h"

class Materials;

struct HitRecord
{
	float t;

	Vec3 p;
	Vec3 normal;
	Materials *pMat;
};
