#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"

class Counter : public GameEntity
{
public:
	Counter();
	~Counter();

	void Update(float deltaTime) override;
};