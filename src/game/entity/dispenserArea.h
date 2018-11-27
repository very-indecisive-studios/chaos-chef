#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"
#include "dispenser.h"

class DispenserArea : public GameEntity
{
private:
	Dispenser *dispenser;
public:
	DispenserArea();
	~DispenserArea();

	Dispenser* GetDispenser() { return dispenser; }
	void SetDispenser(Dispenser* inputDispenser) { dispenser = inputDispenser; }

	void Update(float deltaTime) override;
};