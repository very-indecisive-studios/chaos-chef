#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"

class DispenserArea : public GameEntity
{
public:
	DispenserArea();
	~DispenserArea();

	void Update(float deltaTime) override;
};