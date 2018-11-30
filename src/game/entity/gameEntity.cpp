#include "gameEntity.h"
#include <iostream>

GameEntity::GameEntity(GameEntityType type)
	: type(type)
{ }

GameEntity::~GameEntity()
{ }

GameEntityType GameEntity::GetType()
{
	return this->type;
}

Vector2 GameEntity::GetPosition()
{
	return this->position;
}

CollisionBounds GameEntity::GetCollisionBounds()
{
	return this->collisionBounds;
}

void GameEntity::SetPosition(Vector2 position)
{
	this->position = position;
}

void GameEntity::SetCollisionBounds(CollisionBounds collisionBounds)
{
	this->collisionBounds = collisionBounds;
}

void GameEntity::Update(float deltaTime)
{ }

void GameEntity::HandleCollision(GameEntity* gameEntity)
{ }

bool GameEntity::CollidedWith(GameEntity *gameEntity)
{
	float thisLeftEdge = position.x;
	float otherLeftEdge = gameEntity->position.x;

	float thisRightEdge = position.x + collisionBounds.bottomRight.x;
	float otherRightEdge = gameEntity->position.x + gameEntity->collisionBounds.bottomRight.x;

	float thisTopEdge = position.y;
	float otherTopEdge = gameEntity->position.y;

	float thisBottomEdge = position.y + collisionBounds.bottomRight.y;
	float otherBottomEdge = gameEntity->position.y + gameEntity->collisionBounds.bottomRight.y;

	// Check for collision using Axis Aligned Bounding Box (AABB)
	if ( (thisRightEdge < otherLeftEdge) || (thisLeftEdge > otherRightEdge) || (thisBottomEdge < otherTopEdge) || (thisTopEdge > otherBottomEdge) )
	{
		return false;
	}
	return true;
}
