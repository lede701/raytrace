#pragma once
#include "Texture.h"
class NoiseTexture : public Texture
{
public:
	float scale;

	NoiseTexture();
	NoiseTexture(float sc);

	~NoiseTexture();

	virtual Vec3 value(float u, float v, const Vec3& p) const;
};

