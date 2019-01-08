#include <iostream>
#include "vehicle.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

Vehicle::Vehicle(std::string textureName, VehicleDirection vehicleDirection) 
    : GameEntity(GameEntityType::VEHICLE), vehicleDirection(vehicleDirection)
{
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(30, 55);

	animSprite = AnimatedSprite::Create(textureName, Layer::VEHICLE, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	animSprite->Play();
}

Vehicle::~Vehicle()
{
	delete animSprite;
}

void Vehicle::Update(float deltaTime)
{
	totalTime += deltaTime;
	
	if(totalTime >= 15)
	{
		vehicleSpeed += 5;
		totalTime = 0;
	}

	if (vehicleDirection == VehicleDirection::UP)
	{
		position.y -= deltaTime * vehicleSpeed;
		animSprite->UpdateAndDraw(deltaTime, position);
	}
	else if (vehicleDirection == VehicleDirection::DOWN)
	{
		position.y += deltaTime * vehicleSpeed;
		animSprite->UpdateAndDraw(deltaTime, position);
	}
}
