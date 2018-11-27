#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"
#include "game/data/food.h"
#include "core/sprites/sprite.h"

class Dispenser : public GameEntity
{
private:
	const PlatedFood *platedFood;
	Sprite *ingreImage = nullptr;

public:
	Dispenser();
	~Dispenser();

	const PlatedFood *GetIngredient();
	void SetIngredient(const PlatedFood * inputPlatedFood);
	Sprite *GetImage();
	void SetImage();
	bool IsActive();

	void Update(float deltaTime) override;
};