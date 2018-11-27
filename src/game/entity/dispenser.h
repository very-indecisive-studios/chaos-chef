#pragma once

#include <iostream>
#include <string>
#include "gameEntity.h"
#include "game/data/food.h"

class Dispenser : public GameEntity
{
private:
	const PlatedFood *platedFood;

public:
	Dispenser();
	~Dispenser();

	const PlatedFood *GetIngredient() { return platedFood; }
	void SetIngredient(const PlatedFood *inputPlatedFood) { platedFood = inputPlatedFood; }
	bool IsActive()
	{
		if (platedFood != NULL)
		{
			return true;
		}
		else return false;
	}

	void Update(float deltaTime) override;
};