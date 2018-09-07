#include "Metal.h"
#include "Utilities.h"



Metal::Metal(const Vec3& a, float f) : albedo(a)
{
	if (f < 1.f) {
		fuzz = f;
	}
	else {
		fuzz = 1.0f;
	}
}


Metal::~Metal()
{
}

bool Metal::Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const
{
	Vec3 reflected = Reflect(unit_vector(r_in.direction()), hit.normal);
	scattered = Ray(hit.p, reflected + fuzz * RandomInUnitSphere());
	attenuation = albedo;
	return (dot(scattered.direction(), hit.normal) > 0);
}
