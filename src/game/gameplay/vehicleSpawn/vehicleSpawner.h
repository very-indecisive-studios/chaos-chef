#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/entity/vehicle/vehicle.h"

class VehicleSpawner
{
private:
	static const int TOTAL_VEHICLES_POOLED = 16;

	float totalTime = 0;
	float elapsedTime1 = 0;
	float elapsedTime2 = 1;
	float elapsedTime3 = 2;
	float spawnTime = 3.0;

	std::queue<Vehicle *> vehicleUpPool;
	std::queue<Vehicle *> vehicleDownPool;

	std::deque<Vehicle *> vehiclesUp1;
	std::deque<Vehicle *> vehiclesUp2;
	std::deque<Vehicle *> vehiclesDown1;
	std::deque<Vehicle *> vehiclesDown2;

	const std::string VEHICLE_UP_IMAGES[3]{ VEHICLE1_UP_IMAGE, VEHICLE2_UP_IMAGE, VEHICLE3_UP_IMAGE };
	const std::string VEHICLE_DOWN_IMAGES[3]{ VEHICLE1_DOWN_IMAGE, VEHICLE2_DOWN_IMAGE, VEHICLE3_DOWN_IMAGE };
	
	AudioPlayer *zoomSoundPlayer;

	void InitializePool(std::queue<Vehicle *> &pool, VehicleDirection dir);
	void DestroyPool(std::queue<Vehicle *> &pool);
	void DestroyPool(std::deque<Vehicle *> &pool);
public:
	VehicleSpawner();
	~VehicleSpawner();
	void Update(float deltaTime);
	void CheckCollisionWithVehicles(GameEntity *entity);
};
