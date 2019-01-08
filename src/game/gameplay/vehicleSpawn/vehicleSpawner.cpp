#include <iostream>
#include <ctime>
#include "vehicleSpawner.h"
#include "game/entity/vehicle/vehicle.h"
#include "core/math.h"
#include "game/data/gameSceneData.h"


VehicleSpawner::VehicleSpawner()
{
	srand(time(nullptr));

	/*
	 * Initialize vehicle pool.
	 */
	InitializePool(vehicleUpPool, VehicleDirection::UP);
	InitializePool(vehicleDownPool, VehicleDirection::DOWN);

	zoomSoundPlayer = AudioPlayer::Create(ZOOM_AUDIO);
	zoomSoundPlayer->SetVolume(0.25f);
	zoomSoundPlayer->SetLooping(true);
	zoomSoundPlayer->Play();
}

VehicleSpawner::~VehicleSpawner()
{
	delete zoomSoundPlayer;

	DestroyPool(vehicleUpPool);
	DestroyPool(vehicleDownPool);
	DestroyPool(vehiclesUp1);
	DestroyPool(vehiclesUp2);
	DestroyPool(vehiclesDown1);
	DestroyPool(vehiclesDown2);
}


void VehicleSpawner::InitializePool(std::queue<Vehicle*>& pool, VehicleDirection dir)
{
	for (int i = 0; i < TOTAL_VEHICLES_POOLED; i++)
	{
		int x = rand() % 3;

		Vehicle *v = nullptr;
		if (dir == VehicleDirection::UP)
		{
		    v = new Vehicle(VEHICLE_UP_IMAGES[x], VehicleDirection::UP);
		}
		else
		{
			v = new Vehicle(VEHICLE_DOWN_IMAGES[x], VehicleDirection::DOWN);
		}

		pool.push(v);
	}
}

void VehicleSpawner::DestroyPool(std::queue<Vehicle*>& pool)
{
	while (!pool.empty())
	{
		delete pool.front();
		pool.pop();
	}
}

void VehicleSpawner::DestroyPool(std::deque<Vehicle*>& pool)
{
	while (!pool.empty())
	{
		delete pool.front();
		pool.pop_front();
	}
}

void VehicleSpawner::Update(float deltaTime)
{
	totalTime += deltaTime;

	for (auto &vehicle : vehiclesUp1)
	{
		vehicle->Update(deltaTime);

		// Only the top vehicle can be out of bounds. This is a queue.
		if (vehicle->GetPosition().y <= GameSceneData::Map::BOUNDS.topLeft.y - vehicle->GetCollisionBounds().bottomRight.y)
		{
			vehicleUpPool.push(vehiclesUp1.front());
			vehiclesUp1.pop_front();
		}
	}

	for (auto &vehicle : vehiclesUp2)
	{
		vehicle->Update(deltaTime);

		// Only the top vehicle can be out of bounds. This is a queue.
		if (vehicle->GetPosition().y <= GameSceneData::Map::BOUNDS.topLeft.y - vehicle->GetCollisionBounds().bottomRight.y)
		{
			vehicleUpPool.push(vehiclesUp2.front());
			vehiclesUp2.pop_front();
		}
	}

	for (auto &vehicle : vehiclesDown1)
	{
		vehicle->Update(deltaTime);

		// Only the top vehicle can be out of bounds. This is a queue.
		if (vehicle->GetPosition().y >= GameSceneData::Map::BOUNDS.bottomRight.y)
		{
			vehicleDownPool.push(vehiclesDown1.front());
			vehiclesDown1.pop_front();
		}
	}

	for (auto &vehicle : vehiclesDown2)
	{
		vehicle->Update(deltaTime);

		// Only the top vehicle can be out of bounds. This is a queue.
		if (vehicle->GetPosition().y >= GameSceneData::Map::BOUNDS.bottomRight.y)
		{
			vehicleDownPool.push(vehiclesDown2.front());
			vehiclesDown2.pop_front();
		}
	}

	if (totalTime >= 15)
	{
		spawnTime -= 0.2;
		totalTime = 0;
	}
	elapsedTime1 += deltaTime;
	elapsedTime2 += deltaTime;
	elapsedTime3 += deltaTime;
	if (elapsedTime1 >= spawnTime)
	{

		Vehicle *v1 = vehicleUpPool.front();
		vehicleUpPool.pop();
		v1->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION1);
		vehiclesUp1.push_back(v1);

		Vehicle *v4 = vehicleDownPool.front();
		vehicleDownPool.pop();
		v4->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION4);
		vehiclesDown2.push_back(v4);

		elapsedTime1 = 0;
	}
	if (elapsedTime2 >= spawnTime)
	{
		Vehicle *v2 = vehicleDownPool.front();
		vehicleDownPool.pop();
		v2->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION2);
		vehiclesDown1.push_back(v2);

		elapsedTime2 = 0;
	}
	if (elapsedTime3 >= spawnTime)
	{
		int x = rand() % 3;
		Vehicle *v3 = vehicleUpPool.front();
		vehicleUpPool.pop();
		v3->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION3);
		vehiclesUp2.push_back(v3);

		elapsedTime3 = 0;
	}
}

void VehicleSpawner::CheckCollisionWithVehicles(GameEntity * entity)
{
	for (Vehicle *v : vehiclesUp1)
	{
		if (entity->CollidedWith(v)) 
		{
			entity->HandleCollision(v);
		}
	}

	for (Vehicle *v : vehiclesUp2)
	{
		if (entity->CollidedWith(v)) 
		{
			entity->HandleCollision(v);
		}
	}
	for (Vehicle *v : vehiclesDown1)
	{
		if (entity->CollidedWith(v))
		{
			entity->HandleCollision(v);
		}
	}
	for (Vehicle *v : vehiclesDown2)
	{
		if (entity->CollidedWith(v))
		{
			entity->HandleCollision(v);
		}
	}
}
