#pragma once
#include "Texture.h"

class CheckerColor : public Texture
{
public:
	Texture* odd;
	Texture* even;
	float size;

	CheckerColor(Texture* t0, Texture* t1, float s = 10);
	~CheckerColor();

	virtual Vec3 value(float u, float v, const Vec3& p) const;
};

