#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"

class TrashBin : public GameEntity
{
public:
	TrashBin();
	~TrashBin();

	void Update(float deltaTime) override;
};