#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"

enum class VehicleDirection { UP, DOWN };

class Vehicle : public GameEntity
{
private:
	AnimatedSprite *currentDownAnimSprite = nullptr;
	AnimatedSprite *currentUpAnimSprite = nullptr;
	AnimatedSprite *vehicleUpAnimSprite1 = AnimatedSprite::Create(VEHICLE1_UP_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleDownAnimSprite1 = AnimatedSprite::Create(VEHICLE1_DOWN_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleUpAnimSprite2 = AnimatedSprite::Create(VEHICLE2_UP_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleDownAnimSprite2 = AnimatedSprite::Create(VEHICLE2_DOWN_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleUpAnimSprite3 = AnimatedSprite::Create(VEHICLE3_UP_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	AnimatedSprite *vehicleDownAnimSprite3 = AnimatedSprite::Create(VEHICLE3_DOWN_IMAGE, 1, VEHICLE_WIDTH, VEHICLE_HEIGHT, VEHICLE_ANIMATION_DELAY);
	CollisionBounds vehicleCB;
	float vehicleSpeed = 75.0f;

public:
	Vehicle(std::string textureName, VehicleDirection vd);
	~Vehicle();
	void Update(float deltaTime) override;
};
