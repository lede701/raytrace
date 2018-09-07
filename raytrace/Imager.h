#pragma once
#include <string>
#include <queue>
#include <mutex>

#include "Camera.h"
#include "Hitable.h"
#include "HitList.h"
#include "Ray.h"
#include "Sphere.h"
#include "stdMaterials.h"
#include "Utilities.h"
#include "Vec3.h"

class Imager
{
private:
	std::queue<Vec3> qVec;
	std::mutex mutex;

	Vec3* aClr;
	void RenderThread(bool isThread = false);

	static unsigned int __stdcall ImagerThread(void *p_this);

	int iComplete;
	int nextComplete;
	int nextStep;

public:
	int x;
	int y;
	int passes;

	int width;
	int height;

	int numThread;

	Camera cam;
	Hitable *world;

	Imager();
	~Imager();

	Vec3 Color(const Ray& r, Hitable* world, int depth = 0);

	void Render(std::string file);


	Vec3 Lerp(float t, Vec3 v1, Vec3 v2);
	Hitable* RandomScene(int size = 500);
};

