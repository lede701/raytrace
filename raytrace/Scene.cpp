#include "Scene.h"



Scene::Scene()
{
}

Scene::Scene(Entity **e, int n)
{
	eList = e;
	size = n;


}

Scene::~Scene()
{
}

bool Scene::hit(const Ray& r, float t_min, float t_max, HitRecord& hr) const
{

}
