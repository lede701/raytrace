#pragma once
#include "AVLTree.h"
#include "Entity.h"
#include "EntityKey.h"
#include "Hitable.h"
#include "Vec3.h"

class Scene : public Hitable
{
public:
	Entity** eList;
	int size;

	Scene();
	Scene(Entity **e, int n);
	~Scene();

	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const;
};
