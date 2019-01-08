#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/data/Layer.h"
#include "core/audio/audio.h"

enum class VehicleDirection { UP, DOWN };

class Vehicle : public GameEntity
{
private:
	AnimatedSprite *animSprite;
	VehicleDirection vehicleDirection;

	float vehicleSpeed = 75.0f;
	float totalTime = 0;

public:
	Vehicle(std::string textureName, VehicleDirection vehicleDirection);
	~Vehicle();

	void Update(float deltaTime) override;
};
