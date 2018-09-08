#include "Lambertian.h"
#include "Utilities.h"


Lambertian::Lambertian(Texture* texture)
{
	albedo = texture;
}


Lambertian::~Lambertian()
{
	if (albedo != NULL)
	{
		delete albedo;
	}
}


bool Lambertian::Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const
{
	Vec3 target = hit.p + hit.normal + RandomInUnitSphere();
	scattered = Ray(hit.p, target - hit.p);
	attenuation = albedo->value(hit.u, hit.v, hit.p);
	return true;
}