#include "Sphere.h"



Sphere::Sphere()
{
}

Sphere::Sphere(Vec3 cen, float r, Materials *mat)
{
	Position(cen);
	radius = r;
	pMat = mat;
}


Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray& r, float t_min, float t_max, HitRecord& hit) const
{
	Vec3 oc = r.origin() - _position;
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
			hit.normal = (hit.p - _position) / radius;
			hit.pMat = pMat;
			return true;
		}
		tmp = (-b + sqrt(discriminant)) / a;
		if (tmp < t_max && tmp > t_min)
		{
			hit.t = tmp;
			hit.p = r.point_at_parameter(hit.t);
			hit.normal = (hit.p - _position) / radius;
			hit.pMat = pMat;
			return true;
		}
	}
	return false;
}