#include "SurfaceNormal.h"
#include "Utilities.h"


SurfaceNormal::SurfaceNormal(Vec3 a) : albedo(a)
{
}


SurfaceNormal::~SurfaceNormal()
{
}

bool SurfaceNormal::Scatter(const Ray& r_in, const HitRecord& hit, Vec3& attenuation, Ray& scattered) const
{
	Vec3 target = hit.p + hit.normal + RandomInUnitSphere();
	scattered = Ray(hit.p, target - hit.p);
	Vec3 N = unit_vector(r_in.point_at_parameter(hit.t) - Vec3(0, 0, -1));
	attenuation = 0.5*Vec3(N.x() + 1, N.y() + 1, N.z() + 1);
	return true;
}
