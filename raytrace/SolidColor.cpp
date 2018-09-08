#include "SolidColor.h"

SolidColor::SolidColor(Vec3 c) : color(c)
{
}


SolidColor::~SolidColor()
{
}

Vec3 SolidColor::value(float u, float v, const Vec3& p) const
{
	return color;
}
