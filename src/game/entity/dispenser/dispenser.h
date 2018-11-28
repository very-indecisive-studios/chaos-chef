#pragma once

#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "game/data/food.h"
#include "core/sprites/sprite.h"

class Dispenser : public GameEntity
{
private:
	const PlatedFood *platedFood	= nullptr;
	Sprite *ingreSprite				= nullptr;

public:
	Dispenser();
	~Dispenser();

	const PlatedFood * GetPlatedFood();
	void SetPlatedFood(const PlatedFood * platedFood);
	bool IsActive();

	void Update(float deltaTime) override;
};