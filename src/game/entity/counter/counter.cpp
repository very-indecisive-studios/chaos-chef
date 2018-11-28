#include <iostream>
#include "counter.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"
#include "context.h"

Counter::Counter() 
	: GameEntity(GameEntityType::COUNTER)
{
	// TODO: define the collision
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(0, 0);
}

Counter::~Counter() 
{ }

void Counter::Update(float deltaTime)
{ }
