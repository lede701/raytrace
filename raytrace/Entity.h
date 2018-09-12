#pragma once
#include <vector>
#include "Vec3.h"
#include "AABB.h"
#include "Ray.h"
#include "HitRecord.h"
#include "EntityKey.h"

class Entity
{
public:
	int CurrentKey;
	std::vector<EntityKey*> KeyFrames;

	Entity();
	Entity(Vec3 position, Vec3 rotation, Vec3 scale);
	~Entity();

	bool Add(EntityKey* key);
	bool Add(Vec3 position, Vec3 rotation, Vec3 scale);

	virtual Vec3& Position();
	virtual Vec3& Rotation();
	virtual Vec3& Scale();

	virtual Vec3& Position(Vec3 position);
	virtual Vec3& Rotation(Vec3 rotation);
	virtual Vec3& Scale(Vec3 scale);

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const = 0;
	virtual AABB& GetAABB() const = 0;
};

