#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"

class TrashBinArea : public GameEntity
{
public:
	TrashBinArea();
	~TrashBinArea();

	void Update(float deltaTime) override;
};