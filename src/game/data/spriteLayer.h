#pragma once
#include <cstdint>

enum class SpriteLayer : uint8_t
{
	BACKGROUND	= 0,
	OVERLAY		= 1,
	VEHICLE		= 2,
	PLAYER		= 3,
	PLATE		= 4,
	FOOD_1		= 5,
	FOOD_2		= 6,
	FOOD_3		= 7,
	FOOD_4		= 8,
	FOOD_5		= 9
};
