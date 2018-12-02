#pragma once

#include "game/data/food.h"
#include "game/hud/hand/handCombHud.h"
#include "game/hud/hand/handIndvHud.h"
#include "game/resources.h"
#include "game/data/gameSceneData.h"

class PlayerHand
{
private:
	static const int MAX_PLATED_FOODS = 5;

	std::vector<const PlatedFood *> foodsOnPlate;
	std::vector<Sprite *> foodsOnPlateSprites;

	HandCombHud handCombHud { GameSceneData::Hud::Top::HAND_COMB_HUD_LOCATION };
	std::vector<HandIndvHud> handIndvHuds
	{
		{ GameSceneData::Hud::Top::HAND_INDV_HUD_LOCATION_1 },
		{ GameSceneData::Hud::Top::HAND_INDV_HUD_LOCATION_2 },
		{ GameSceneData::Hud::Top::HAND_INDV_HUD_LOCATION_3 },
		{ GameSceneData::Hud::Top::HAND_INDV_HUD_LOCATION_4 },
		{ GameSceneData::Hud::Top::HAND_INDV_HUD_LOCATION_5 }
	};

	void AddPlatedFoodToHuds(const PlatedFood *platedFood);
	void ResetHuds();
public:
	PlayerHand();
	~PlayerHand();

	void Add(const PlatedFood *platedFood);
	void Empty();

	void Update(float deltaTime, Vector2 playerPosition);
};
