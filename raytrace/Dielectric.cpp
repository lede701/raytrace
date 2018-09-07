#include "Dielectric.h"
#include "Vec3.h"
#include "Utilities.h"


Dielectric::Dielectric(float idx) : refIdx(idx)
{
}


Dielectric::~Dielectric()
{
}

bool Dielectric::Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const
{
	Vec3 outwardNormal;
	Vec3 reflected = Reflect(r_in.direction(), hit.normal);
	float ni_over_nt;
	attenuation = Vec3(1.0f, 1.0f, 1.0f);
	Vec3 refracted;
	float reflectProb = 1.0f;
	float cosine;

	if (dot(r_in.direction(), hit.normal) > 0)
	{
		outwardNormal = -hit.normal;
		ni_over_nt = refIdx;
		cosine = refIdx * dot(r_in.direction(), hit.normal) / r_in.direction().length();
	}
	else
	{
		outwardNormal = hit.normal;
		ni_over_nt = 1.0f / refIdx;
		cosine = -dot(r_in.direction(), hit.normal) / r_in.direction().length();
	}
	if (Refract(r_in.direction(), outwardNormal, ni_over_nt, refracted))
	{
		reflectProb = Schlick(cosine, refIdx);
	}

	if (drand48() < reflectProb)
	{
		scattered = Ray(hit.p, reflected);
	}
	else
	{
		scattered = Ray(hit.p, refracted);
	}

	return true;
}