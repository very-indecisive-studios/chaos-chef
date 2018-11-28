#pragma once

#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"

class Counter : public GameEntity
{
public:
	Counter();
	~Counter();

	void Update(float deltaTime) override;
};