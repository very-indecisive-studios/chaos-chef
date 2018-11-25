#include "gameEntity.h"

core::GameEntity::GameEntity(GameEntityType type)
	: type(type)
{ }

core::GameEntity::~GameEntity()
{ }

void core::GameEntity::Collided(GameEntity &gameEntity)
{

}