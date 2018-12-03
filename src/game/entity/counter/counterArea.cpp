#include <iostream>
#include "counterArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

CounterArea::CounterArea() 
	: GameEntity(GameEntityType::COUNTER_AREA)
{
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(10, 10);
}

CounterArea::~CounterArea()
{ }


void CounterArea::Update(float deltaTime)
{ }
