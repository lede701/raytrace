#include "Vec3.h"



Vec3::Vec3()
{
	e[0] = e[1] = e[2] = 0.0f;
}

Vec3::Vec3(float e0, float e1, float e2)
{
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}


Vec3::~Vec3()
{
}



