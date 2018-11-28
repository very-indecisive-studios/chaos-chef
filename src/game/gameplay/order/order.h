#pragma once
#include "game/data/food.h"

struct Order
{
	const Meal *meal;
	float timeRemainingSeconds;
};
