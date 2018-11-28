#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"

class Vehicle : public GameEntity
{
private:
	AnimatedSprite *currentAnimSprite = nullptr;
	AnimatedSprite *vehicleUpAnimSprite = AnimatedSprite::Create(VEHICLE1_UP_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleDownAnimSprite = AnimatedSprite::Create(VEHICLE1_DOWN_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);

	float vehicleSpeed = 100.0f;

public:
	Vehicle();
	~Vehicle();

	void Update(float deltaTime) override;
};