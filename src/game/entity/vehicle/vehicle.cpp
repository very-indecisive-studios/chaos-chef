#include <iostream>
#include "vehicle.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

Vehicle::Vehicle(std::string textureName, VehicleDirection vd) : GameEntity(GameEntityType::VEHICLE)
{
	vehicleD = vd;
	
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(32, 64);


	if (textureName == VEHICLE1_UP_IMAGE)
	{
		currentUpAnimSprite = vehicleUpAnimSprite1;
	}
	else if (textureName == VEHICLE2_UP_IMAGE)
	{
		currentUpAnimSprite = vehicleUpAnimSprite2;
	}
	else if (textureName == VEHICLE3_UP_IMAGE)
	{
		currentUpAnimSprite = vehicleUpAnimSprite3;
	}
	if (textureName == VEHICLE1_DOWN_IMAGE)
	{
		currentDownAnimSprite = vehicleDownAnimSprite1;
	}
	else if (textureName == VEHICLE2_DOWN_IMAGE)
	{
		currentDownAnimSprite = vehicleDownAnimSprite2;
	}
	else if (textureName == VEHICLE3_DOWN_IMAGE)
	{
		currentDownAnimSprite = vehicleDownAnimSprite3;
	}
}

Vehicle::~Vehicle()
{

}

void Vehicle::Update(float deltaTime)
{
	if (vehicleD == VehicleDirection::UP)
	{
		currentUpAnimSprite->Play();
		position.y -= deltaTime * vehicleSpeed;
		currentUpAnimSprite->UpdateAndDraw(deltaTime, position);
	}
	if (vehicleD == VehicleDirection::DOWN)
	{
		currentDownAnimSprite->Play();
		position.y += deltaTime * vehicleSpeed;
		currentDownAnimSprite->UpdateAndDraw(deltaTime, position);
	}
}
