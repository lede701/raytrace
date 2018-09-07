#include "Entity.h"



Entity::Entity()
{
	// Create an initial keyframe at the origin
	EntityKey *key = new EntityKey();
	key->position = Vec3(0.0f, 0.0f, 0.0f);
	key->rotation = Vec3(0.0f, 0.0f, 0.0f);
	key->scale = Vec3(1.0f, 1.0f, 1.0f);
	Add(key);
}

Entity::Entity(Vec3 position, Vec3 rotation, Vec3 scale)
{
	EntityKey *key = new EntityKey();
	key->position = position;
	key->rotation = rotation;
	key->scale = scale;
	Add(key);
	CurrentKey = 0;
}

Entity::~Entity()
{
	while (KeyFrames.size() > 0)
	{
		EntityKey* delme = KeyFrames.back();
		KeyFrames.pop_back();
		delete delme;
	}
}

bool Entity::Add(EntityKey* key)
{
	key->keyId = KeyFrames.size();
	KeyFrames.push_back(key);
	return true;
}

bool Entity::Add(Vec3 position, Vec3 rotation, Vec3 scale)
{
	EntityKey *key = new EntityKey();
	key->position = position;
	key->rotation = rotation;
	key->scale = scale;
	return Add(key);
}

Vec3& Entity::Position()
{
	return KeyFrames[CurrentKey]->position;
}

Vec3& Entity::Position(Vec3 position)
{
	KeyFrames[CurrentKey]->position = position;
	return Position();
}

Vec3& Entity::Rotation()
{
	return KeyFrames[CurrentKey]->rotation;
}

Vec3& Entity::Rotation(Vec3 rotation)
{
	KeyFrames[CurrentKey]->rotation = rotation;
	return Rotation();
}

Vec3& Entity::Scale()
{
	return KeyFrames[CurrentKey]->scale;
}


Vec3& Entity::Scale(Vec3 scale)
{
	KeyFrames[CurrentKey]->scale = scale;
	return Scale();
}