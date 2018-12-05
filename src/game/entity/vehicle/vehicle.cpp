#include <iostream>
#include "vehicle.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

Vehicle::Vehicle(std::string textureName, VehicleDirection vd) : GameEntity(GameEntityType::VEHICLE)
{
	if (textureName == VEHICLE1_UP_IMAGE)
	{
		currentUpAnimSprite = vehicleUpAnimSprite1;
	}
	else if (textureName == VEHICLE2_UP_IMAGE)
	{
		currentUpAnimSprite = vehicleUpAnimSprite2;
	}
	else
	{
		currentUpAnimSprite = vehicleUpAnimSprite3;
	}
}

Vehicle::~Vehicle()
{

}

void Vehicle::Update(float deltaTime)
{
	if (position.x == 176)
	{
		currentUpAnimSprite->Play();
		position.y -= deltaTime * vehicleSpeed;
		currentUpAnimSprite->UpdateAndDraw(deltaTime, position);
	}
	if (position.x == 464)
	{
		currentUpAnimSprite->Play();
		position.y += deltaTime * vehicleSpeed;
		currentUpAnimSprite->UpdateAndDraw(deltaTime, position);
	}
	if (position.x == 272)
	{
		currentUpAnimSprite->Play();
		position.y += deltaTime * vehicleSpeed;
		currentUpAnimSprite->UpdateAndDraw(deltaTime, position);
	}
	if (position.x == 368)
	{
		currentUpAnimSprite->Play();
		position.y -= deltaTime * vehicleSpeed;
		currentUpAnimSprite->UpdateAndDraw(deltaTime, position);
	}
}
