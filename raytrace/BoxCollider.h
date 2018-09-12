#pragma once
#include "Vec3.h"

class BoxCollider
{
public:
	Vec3 Point1;
	Vec3 Point2;

	BoxCollider();
	BoxCollider(Vec3 p1, Vec3 p2);

	~BoxCollider();
};

