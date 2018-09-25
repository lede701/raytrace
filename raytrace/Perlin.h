#pragma once

#include "Vec3.h"

class Perlin
{
public:
	int ranSize;
	Vec3* ranvec;
	int* perm_x;
	int* perm_y;
	int* perm_z;

	Perlin();
	~Perlin();

	float noise(const Vec3& p) const;

	float PerlinInterp(Vec3 c[2][2][2], float u, float v, float w) const;
	Vec3* PerlinGenerate(int n = 256);
	void Permute(int* p, int n);
	int* PerlingGeneratePerm();
	float Turb(const Vec3& p, int depth = 7) const;

};

