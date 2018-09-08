#include "Utilities.h"
#include <time.h>
#include <random>


Vec3 RandomInUnitSphere()
{
	Vec3 p;
	do {
		p = 2.0*Vec3(drand48(), drand48(), drand48()) - Vec3(1, 1, 1);
	} while (p.squared_length() >= 1.0);
	return p;
}

Vec3 RandomInUnitDisk()
{
	Vec3 p;
	do
	{
		p = 2.0f*Vec3(drand48(), drand48(), 0.0f) - Vec3(1.0f, 1.0f, 0.0f);
	} while ((dot(p, p) >= 1.0f));
	return p;
}

std::random_device rd;
std::mt19937 gen(rd());

float drand48()
{
	float num = float(gen()) / float(gen.max() + 1.0f);
	return num;
}

Vec3 Reflect(const Vec3& v, const Vec3& n)
{
	return v - 2 * dot(v, n)*n;
}

bool Refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted)
{
	Vec3 uv = unit_vector(v);
	float dt = dot(uv, n);
	float discriminant = 1.0f - ni_over_nt * ni_over_nt*(1.0f - dt * dt);
	if (discriminant > 0)
	{
		refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
		return true;
	}
	return false;
}

float Schlick(float cosine, float refIdx)
{
	float r0 = (1 - refIdx) / (1 + refIdx);
	r0 = r0 * r0;
	return r0 + (1 - r0)*pow((1 - cosine), 5);
}

float ffmin(float a, float b)
{
	return a < b ? a : b;
}

float ffmax(float a, float b)
{
	return a > b ? a : b;
}