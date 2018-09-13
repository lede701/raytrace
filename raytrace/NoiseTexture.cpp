#include "NoiseTexture.h"



NoiseTexture::NoiseTexture()
{
}

NoiseTexture::NoiseTexture(float sc) : scale(sc)
{

}


NoiseTexture::~NoiseTexture()
{
}

Vec3 NoiseTexture::value(float u, float v, const Vec3& p) const
{
	return Vec3(0, 0, 0);
}