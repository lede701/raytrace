#pragma once

#include "Vec3.h"

Vec3 RandomInUnitSphere();
Vec3 RandomInUnitDisk();
float drand48();

Vec3 Reflect(const Vec3& v, const Vec3& n);
bool Refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted);

float Schlick(float cosine, float refIdx);
