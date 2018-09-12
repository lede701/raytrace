#include "BoxCollider.h"



BoxCollider::BoxCollider()
{
	Point1 = Vec3(0.0f, 0.0f, 0.0f);
	Point2 = Vec3(0.0f, 0.0f, 0.0f);
}

BoxCollider::BoxCollider(Vec3 p1, Vec3 p2)
{
	Point1 = p1;
	Point2 = p2;
}


BoxCollider::~BoxCollider()
{
}
