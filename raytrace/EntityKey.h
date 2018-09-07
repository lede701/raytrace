#pragma once
#include "Vec3.h"

struct EntityKey
{
public:
	int keyId;
	int frame;
	Vec3 position;
	Vec3 rotation;
	Vec3 scale;
};

