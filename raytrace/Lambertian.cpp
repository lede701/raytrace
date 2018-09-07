#include "Lambertian.h"
#include "Utilities.h"


Lambertian::Lambertian(const Vec3& a) : albedo(a)
{
}


Lambertian::~Lambertian()
{
}


bool Lambertian::Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const
{
	Vec3 target = hit.p + hit.normal + RandomInUnitSphere();
	scattered = Ray(hit.p, target - hit.p);
	attenuation = albedo;
	return true;
}