#include <iostream>
#include <ctime>
#include "vehicleSpawner.h"
#include "game/entity/vehicle/vehicle.h"
#include "core/math.h"
#include "game/data/gameSceneData.h"


VehicleSpawner::VehicleSpawner()
{
	srand(time(nullptr));
}

VehicleSpawner::~VehicleSpawner()
{

}

void VehicleSpawner::Update(float deltaTime)
{
	if (!vehiclesUp1.empty())
	{
		for (int i = 0; i < vehiclesUp1.size(); i++)
		{
			vehiclesUp1[i]->Update(deltaTime);
			if (vehiclesUp1[i]->GetPosition().y <= GameSceneData::Map::BOUNDS.topLeft.y) 
			{
				delete vehiclesUp1[i];
				vehiclesUp1.erase(vehiclesUp1.begin() + i);
			}
		}
	}
	if (!vehiclesUp2.empty())
	{
		for (int i = 0; i < vehiclesUp2.size(); i++)
		{
			vehiclesUp2[i]->Update(deltaTime);
			if (vehiclesUp2[i]->GetPosition().y <= GameSceneData::Map::BOUNDS.topLeft.y)
			{
				delete vehiclesUp2[i];
				vehiclesUp2.erase(vehiclesUp2.begin() + i);
			}
		}
	}
	if (!vehiclesDown1.empty())
	{
		for (int i = 0; i < vehiclesDown1.size(); i++)
		{
			vehiclesDown1[i]->Update(deltaTime);
			if (vehiclesDown1[i]->GetPosition().y >= (GameSceneData::Map::BOUNDS.bottomRight.y-60))
			{
				delete vehiclesDown1[i];
				vehiclesDown1.erase(vehiclesDown1.begin() + i);
			}
		}
	}
	if (!vehiclesDown2.empty())
	{
		for (int i = 0; i < vehiclesDown2.size(); i++)
		{
			vehiclesDown2[i]->Update(deltaTime);
			if (vehiclesDown2[i]->GetPosition().y >= GameSceneData::Map::BOUNDS.bottomRight.y-60)
			{
				delete vehiclesDown2[i];
				vehiclesDown2.erase(vehiclesDown2.begin() + i);
			}
		}
	}
	elapsedTime1 += deltaTime;
	elapsedTime2 += deltaTime;
	elapsedTime3 += deltaTime;
	if (elapsedTime1 >= spawnTime)
	{
		int x = rand() % 3;
		Vehicle *v1 = new Vehicle(VEHICLE_UP_IMAGES[x], VehicleDirection::UP);
		v1->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION1);
		v1->Update(deltaTime);
		vehiclesUp1.push_back(v1);
		int y = rand() % 3;
		Vehicle *v4 = new Vehicle(VEHICLE_DOWN_IMAGES[y], VehicleDirection::DOWN);
		v4->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION4);
		vehiclesDown2.push_back(v4);
		elapsedTime1 = 0;
	}
	if (elapsedTime2 >= spawnTime)
	{
		int x = rand() % 3;
		Vehicle *v2 = new Vehicle(VEHICLE_DOWN_IMAGES[x], VehicleDirection::DOWN);
		v2->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION2);
		v2->Update(deltaTime);
		vehiclesDown1.push_back(v2);
		elapsedTime2 = 0;
	}
	if (elapsedTime3 >= spawnTime)
	{
		int x = rand() % 3;
		Vehicle *v3 = new Vehicle(VEHICLE_UP_IMAGES[x], VehicleDirection::UP);
		v3->SetPosition(GameSceneData::Map::VEHICLE_SPAWN_LOCATION3);
		v3->Update(deltaTime);
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
