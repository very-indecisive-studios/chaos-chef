#include "gameEntity.h"
#include <iostream>

GameEntity::GameEntity(GameEntityType type)
	: type(type)
{ }

GameEntity::~GameEntity()
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