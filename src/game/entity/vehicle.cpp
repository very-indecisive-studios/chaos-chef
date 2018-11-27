#include <iostream>
#include "vehicle.h"
#include "gameEntity.h"
#include "core/math.h"

Vehicle::Vehicle() : GameEntity(GameEntityType::VEHICLE) 
{
	currentAnimSprite = vehicleDownAnimSprite;
}

Vehicle::~Vehicle() {}

void Vehicle::Update(float deltaTime)
{
	currentAnimSprite->Play();
	position.y += deltaTime * vehicleSpeed;
	currentAnimSprite->UpdateAndDraw(deltaTime, position);
}
