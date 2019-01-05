#include <iostream>
#include "dispenserArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

DispenserArea::DispenserArea() 
	: GameEntity(GameEntityType::DISPENSER_AREA)
{
	collisionBounds.topLeft		= Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(8, 8);
}

DispenserArea::~DispenserArea()
{
	
}

Dispenser* DispenserArea::GetDispenser()
{
	return dispenser;
}

void DispenserArea::SetDispenser(Dispenser* dispenser)
{
	this->dispenser = dispenser;
}

void DispenserArea::Update(float deltaTime)
{ }
