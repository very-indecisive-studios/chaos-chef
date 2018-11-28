#pragma once

#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "dispenser.h"

class DispenserArea : public GameEntity
{
private:
	Dispenser *dispenser;
public:
	DispenserArea();
	~DispenserArea();

	Dispenser* GetDispenser();
	void SetDispenser(Dispenser *dispenser);

	void Update(float deltaTime) override;
};