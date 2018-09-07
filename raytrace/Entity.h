#pragma once
#include <list>
#include "Vec3.h"
#include "Ray.h"
#include "HitRecord.h"

class Entity
{
public:
	Vec3 _position;
	Vec3 _rotation;
	Vec3 _scale;

	

	Entity();
	Entity(Vec3 position, Vec3 rotation, Vec3 scale);
	~Entity();

	virtual bool AddKey();

	virtual Vec3& Position();
	virtual Vec3& Rotation();
	virtual Vec3& Scale();

	virtual Vec3& Position(Vec3 position);
	virtual Vec3& Rotation(Vec3 rotation);
	virtual Vec3& Scale(Vec3 scale);

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const = 0;

};

