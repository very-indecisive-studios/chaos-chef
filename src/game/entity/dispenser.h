#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"

class Dispenser : public GameEntity
{
public:
	Dispenser();
	~Dispenser();

	void Update(float deltaTime) override;
};