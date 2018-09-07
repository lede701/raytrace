#pragma once
#include "Vec3.h"
#include "Ray.h"

class Camera
{
public:
	Vec3 origin;
	Vec3 lowerLeftCorner;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 u, v, w;
	float lenseRadius;

	Camera();
	Camera(float vFov, float aspect);
	Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vup, float vFov, float aspect, float aperture, float focusDist);
	~Camera();

	Ray getRay(float u, float v);
};

