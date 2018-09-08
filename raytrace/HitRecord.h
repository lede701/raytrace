#pragma once
#include "Vec3.h"

class Materials;

struct HitRecord
{
	float t;
	float u;
	float v;

	Vec3 p;
	Vec3 normal;
	Materials *pMat;
};
