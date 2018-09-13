#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h>


Sphere::Sphere()
{
}

Sphere::Sphere(Vec3 cen, float r, Materials *mat)
{
	Position(cen);
	radius = r;
	pMat = mat;

	Vec3 p1 = cen - Vec3(r, r, r);
	Vec3 p2 = cen + Vec3(r, r, r);
	_aabb = AABB(p1, p2);
}


Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray& r, float t_min, float t_max, HitRecord& hit) const
{
	Vec3 pos = KeyFrames[CurrentKey]->position;
	Vec3 oc = r.origin() - pos;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		float tmp = (-b - sqrt(discriminant)) / a;
		if (tmp < t_max && tmp > t_min )
		{
			hit.t = tmp;
			hit.p = r.point_at_parameter(hit.t);
			//GetSphereUV((hit.p - pos / radius), hit.u, hit.v);
			hit.normal = (hit.p - pos) / radius;
			hit.pMat = pMat;
			return true;
		}
		tmp = (-b + sqrt(discriminant)) / a;
		if (tmp < t_max && tmp > t_min)
		{
			hit.t = tmp;
			hit.p = r.point_at_parameter(hit.t);
			hit.normal = (hit.p - pos) / radius;
			hit.pMat = pMat;
			return true;
		}
	}
	return false;
}

void Sphere::GetSphereUV(const Vec3& p, float& u, float &v)
{
	float phi = atan2(p.z(), p.x());
	float theta = asin(p.y());
	u = 1 - (phi + M_PI) / (2 * M_PI);
	v = (theta + M_PI / 2) / M_PI;
}

AABB Sphere::GetAABB() const
{
	return _aabb;
}