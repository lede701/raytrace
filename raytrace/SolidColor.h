#pragma once
#include "Vec3.h"
#include "Texture.h"

class SolidColor : public Texture
{
public:
	Vec3 color;

	SolidColor(Vec3 c);
	~SolidColor();

	virtual Vec3 value(float u, float v, const Vec3& p) const;
};

