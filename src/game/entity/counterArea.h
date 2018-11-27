#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"

class CounterArea : public GameEntity
{
public:
	CounterArea();
	~CounterArea();

	void Update(float deltaTime) override;
};