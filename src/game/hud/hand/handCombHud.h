#pragma once

#include "game/hud/hud.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/data/food.h"
#include "game/data/Layer.h"
#include "handIndvHud.h"
#include "core/text/text.h"

class HandCombHud : public Hud
{
private:
	Sprite *plateSprite				= Sprite::Create(EMPTY_PLATE_IMAGE, Layer::PLATE, GameSceneData::Hud::Top::HAND_COMB_HUD_PF_SCALE);
	Sprite *platedFoodSprites[5]	= { nullptr };
public:
	HandCombHud(Vector2 position);
	~HandCombHud();

	void AddPlatedFood(const PlatedFood *food);
	void ClearAllPlatedFood();

	void Update(float deltaTime) override;
};
