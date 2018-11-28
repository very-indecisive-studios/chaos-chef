#include <iostream>
#include "counterArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

CounterArea::CounterArea() 
	: GameEntity(GameEntityType::COUNTER_AREA)
{
	// TODO: define the collision
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(0, 0);
}

CounterArea::~CounterArea()
{ }


void CounterArea::Update(float deltaTime)
{ }
