#include "Entity.h"



Entity::Entity()
{
}

Entity::Entity(Vec3 position, Vec3 rotation, Vec3 scale)
{
	_position = position;
	_rotation = rotation;
	_scale = scale;
}

Entity::~Entity()
{
}

bool Entity::AddKey()
{
	return true;
}

Vec3& Entity::Position()
{
	return _position;
}

Vec3& Entity::Position(Vec3 position)
{
	_position = position;
	return _position;
}

Vec3& Entity::Rotation()
{
	return _rotation;
}

Vec3& Entity::Rotation(Vec3 rotation)
{
	_rotation = rotation;
	return _rotation;
}

Vec3& Entity::Scale()
{
	return _scale;
}


Vec3& Entity::Scale(Vec3 scale)
{
	_scale = scale;
	return _scale;
}