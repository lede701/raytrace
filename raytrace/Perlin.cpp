#include "Perlin.h"
#include "Utilities.h"


Perlin::Perlin()
{
	ranvec = PerlinGenerate();
}


Perlin::~Perlin()
{
}

float Perlin::PerlinInterp(Vec3 c[2][2][2], float u, float v, float w) const
{
	float uu = u * u*(3 - 2 * u);
	float vv = v * v*(3 - 2 * v);
	float ww = w * w*(3 - 2 * w);
	float accum = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				Vec3 weight_v(u = i, v - j, w - k);
				accum += (i*uu + (1 - i)*(1 - uu))
					* (j*vv + (1 - j)*(1 - vv))
					* (k*ww + (1 - k)*(1 - ww)) * dot(c[i][j][k], weight_v);
			}
		}
	}
	return accum;
}

float Perlin::noise(const Vec3& p) const
{
	float u = p.x() - floor(p.x());
	float v = p.y() - floor(p.y());
	float w = p.z() - floor(p.z());
	int i = floor(p.x());
	int j = floor(p.y());
	int k = floor(p.z());
	Vec3 c[2][2][2];
	for (int di = 0; di < 2; ++di)
	{
		for (int dj = 0; dj < 2; ++dj)
		{
			for (int dk = 0; dk < 2; ++dk)
			{
				c[di][dj][dk] = ranvec[perm_x[(i + di) & 255] ^ perm_y[(j + dj) & 255] ^ perm_z[(k + dk) & 255]];
			}
		}
	}
	return PerlinInterp(c, u, v, w);
}

Vec3* Perlin::PerlinGenerate(int n)
{
	Vec3* p = new Vec3[n];
	for (int i = 0; i < n; ++i)
	{
		p[i] = unit_vector(Vec3(-1 + 2 * drand48(), -1 + 2 * drand48(), -1 + 2 * drand48()));
	}

	return p;
}
