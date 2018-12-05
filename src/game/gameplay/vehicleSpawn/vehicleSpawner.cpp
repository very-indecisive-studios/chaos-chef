#include <iostream>
#include <ctime>
#include "vehicleSpawner.h"
#include "game/entity/vehicle/vehicle.h"
#include "core/math.h"


VehicleSpawner::VehicleSpawner()
{
	srand(time(nullptr));
}

VehicleSpawner::~VehicleSpawner()
{

}

void VehicleSpawner::Update(float deltaTime)
{
	vehicleCB.topLeft = Vector2(0, 0);
	vehicleCB.bottomRight = Vector2(32, 64);
	if (!vehiclesUp1.empty())
	{
		for (int i = 0; i < vehiclesUp1.size(); i++)
		{
			vehiclesUp1[i]->Update(deltaTime);
		}
	}
	if (!vehiclesUp2.empty())
	{
		for (int i = 0; i < vehiclesUp2.size(); i++)
		{
			vehiclesUp2[i]->Update(deltaTime);
		}
	}
	if (!vehiclesDown1.empty())
	{
		for (int i = 0; i < vehiclesDown1.size(); i++)
		{
			vehiclesDown1[i]->Update(deltaTime);
		}
	}
	if (!vehiclesDown2.empty())
	{
		for (int i = 0; i < vehiclesDown2.size(); i++)
		{
			vehiclesDown2[i]->Update(deltaTime);
		}
	}
	elapsedTime1 += deltaTime;
	elapsedTime2 += deltaTime;
	elapsedTime3 += deltaTime;
	if (elapsedTime1 >= 3.0)
	{
		int x = rand() % 3;
		Vehicle *v1 = new Vehicle(VEHICLE_UP_IMAGES[x], VehicleDirection::UP);
		v1->SetPosition(Vector2(176, 275));
		v1->SetCollisionBounds(vehicleCB);
		v1->Update(deltaTime);
		vehiclesUp1.push_back(v1);
		int y = rand() % 3;
		Vehicle *v4 = new Vehicle(VEHICLE_DOWN_IMAGES[y], VehicleDirection::DOWN);
		v4->SetPosition(Vector2(464, 0));
		v4->SetCollisionBounds(vehicleCB);
		vehiclesDown2.push_back(v4);
		elapsedTime1 = 0;
	}
	if (elapsedTime2 >= 3.0)
	{
		int x = rand() % 3;
		Vehicle *v2 = new Vehicle(VEHICLE_DOWN_IMAGES[x], VehicleDirection::DOWN);
		v2->SetPosition(Vector2(272, 0));
		v2->SetCollisionBounds(vehicleCB);
		v2->Update(deltaTime);
		vehiclesDown1.push_back(v2);
		elapsedTime2 = 0;
	}
	if (elapsedTime3 >= 3.0)
	{
		int x = rand() % 3;
		Vehicle *v3 = new Vehicle(VEHICLE_UP_IMAGES[x], VehicleDirection::UP);
		v3->SetPosition(Vector2(368, 275));
		v3->SetCollisionBounds(vehicleCB);
		v3->Update(deltaTime);
		vehiclesUp2.push_back(v3);
		elapsedTime3 = 0;
	}
}
