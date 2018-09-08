#include "CheckerColor.h"



CheckerColor::CheckerColor(Texture* t0, Texture* t1, float s)
{
	even = t0;
	odd = t1;
	size = s;
}


CheckerColor::~CheckerColor()
{
}

Vec3 CheckerColor::value(float u, float v, const Vec3& p) const
{
	float sines = sin(size * p.x()) * sin(size * p.y())*sin(size * p.z());
	if (sines < 0)
	{
		return odd->value(u, v, p);
	}
	else
	{
		return even->value(u, v, p);
	}
}