#pragma once

#include "game/data/food.h"
#include "game/hud/hand/handCombHud.h"
#include "game/hud/hand/handIndvHud.h"
#include "game/resources.h"

class PlayerHand
{
private:
	const PlatedFood *foodsOnPlate[5] = { nullptr };

	HandCombHud handCombHud { Vector2(MAP_WIDTH - HAND_COMB_HUD_WIDTH, MAP_HEIGHT) };
	HandIndvHud handIndvHuds[5]
	{
		{ Vector2(MAP_WIDTH - HAND_INDV_HUD_WIDTH * 2, MAP_HEIGHT + (HAND_COMB_HUD_HEIGHT - HAND_INDV_HUD_HEIGHT)) },
		{ Vector2(MAP_WIDTH - HAND_INDV_HUD_WIDTH * 3, MAP_HEIGHT + (HAND_COMB_HUD_HEIGHT - HAND_INDV_HUD_HEIGHT)) },
		{ Vector2(MAP_WIDTH - HAND_INDV_HUD_WIDTH * 4, MAP_HEIGHT + (HAND_COMB_HUD_HEIGHT - HAND_INDV_HUD_HEIGHT)) },
		{ Vector2(MAP_WIDTH - HAND_INDV_HUD_WIDTH * 5, MAP_HEIGHT + (HAND_COMB_HUD_HEIGHT - HAND_INDV_HUD_HEIGHT)) },
		{ Vector2(MAP_WIDTH - HAND_INDV_HUD_WIDTH * 6, MAP_HEIGHT + (HAND_COMB_HUD_HEIGHT - HAND_INDV_HUD_HEIGHT)) }
	};

	void AddPlatedFoodToHuds(const PlatedFood *platedFood);
	void ResetHuds();
public:
	PlayerHand();
	~PlayerHand();

	void Add(const PlatedFood *platedFood);
	void Empty();

	void Update(float deltaTime);
};
