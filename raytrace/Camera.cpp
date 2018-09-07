#include "Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Utilities.h"



Camera::Camera()
{
	lowerLeftCorner = Vec3(-2.0f, -1.0f, -1.0f);
	horizontal = Vec3(4.0f, 0.0f, 0.0f);
	vertical = Vec3(0.0f, 2.0f, 0.0f);
	origin = Vec3(0.0f, 0.0f, 0.0f);
}

Camera::Camera(float vFov, float aspect)
{
	float theta = vFov * M_PI / 180.0f;
	float halfHeight = tan(theta / 2);
	float halfWidth = aspect * halfHeight;
	lowerLeftCorner = Vec3(-halfWidth, -halfHeight, -1.0f);
	horizontal = Vec3(2 * halfWidth, 0.0f, 0.0f);
	vertical = Vec3(0.0f, 2 * halfHeight, 0.0f);
	origin = Vec3(0.0f, 0.0f, 0.0f);

}

Camera::Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 vup, float vFov, float aspect, float aperture, float focusDist)
{
	lenseRadius = aperture / 2;
	float theta = vFov * M_PI / 180.0f;
	float halfHeight = tan(theta / 2);
	float halfWidth = aspect * halfHeight;
	origin = lookFrom;
	w = unit_vector(lookFrom - lookAt);
	u = unit_vector(cross(vup, w));
	v = cross(w, u);

	lowerLeftCorner = origin - halfWidth * focusDist * u - halfHeight * focusDist * v - w * focusDist;
	horizontal = 2 * halfWidth*focusDist*u;
	vertical = 2 * halfHeight*focusDist*v;
}


Camera::~Camera()
{
}

Ray Camera::getRay(float s, float t)
{
	Vec3 rd = lenseRadius * RandomInUnitDisk();
	Vec3 offset = u * rd.x() + v * rd.y();
	return Ray(origin + offset, lowerLeftCorner + s * horizontal + t * vertical - origin - offset);
}
