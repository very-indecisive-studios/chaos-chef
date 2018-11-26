#include "gameEntity.h"
#include <iostream>

GameEntity::GameEntity(GameEntityType type)
	: type(type)
{ }

GameEntity::~GameEntity()
{ }

bool GameEntity::CollidedWith(GameEntity &gameEntity, float thisHeight, float otherHeight, float thisWidth, float otherWidth)
{
	float thisLeftEdge = position.x;
	float otherLeftEdge = gameEntity.position.x;


	float thisRightEdge = position.x + thisWidth;
	float otherRightEdge = position.x + otherWidth;

	float thisTopEdge = position.y;
	float otherTopEdge = gameEntity.position.y;

	float thisBottomEdge = position.y + thisHeight;
	float otherBottomEdge = gameEntity.position.y + otherHeight;

	// Check for collision using Axis Aligned Bounding Box (AABB)
	if ( (thisRightEdge < otherLeftEdge) || (thisLeftEdge > otherRightEdge) || (thisBottomEdge < otherTopEdge) || (thisTopEdge > otherBottomEdge) )
	{
		return false;
	}
	return true;
}