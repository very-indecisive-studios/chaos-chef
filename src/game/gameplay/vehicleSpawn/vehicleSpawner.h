#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/entity/vehicle/vehicle.h"

static const std::string VEHICLE_UP_IMAGES[3]{ VEHICLE1_UP_IMAGE, VEHICLE2_UP_IMAGE, VEHICLE3_UP_IMAGE };
static const std::string VEHICLE_DOWN_IMAGES[3]{ VEHICLE1_DOWN_IMAGE, VEHICLE2_DOWN_IMAGE, VEHICLE3_DOWN_IMAGE };

class VehicleSpawner
{
private:
	float elapsedTime1 = 0;
	float elapsedTime2 = 1;
	float elapsedTime3 = 2;
	float vehicleSpeed = 75.0f;
	CollisionBounds vehicleCB;
	std::vector <Vehicle *> vehiclesUp1;
	std::vector <Vehicle *> vehiclesDown1;
	std::vector <Vehicle *> vehiclesUp2;
	std::vector <Vehicle *> vehiclesDown2;

public:
	VehicleSpawner();
	~VehicleSpawner();
	void Update(float deltaTime);
};
