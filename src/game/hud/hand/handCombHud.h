#pragma once

#include "game/hud/hud.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/data/food.h"
#include "game/data/Layer.h"

class HandCombHud : public Hud
{
private:
	Sprite *plateSprite				= Sprite::Create(EMPTY_PLATE_IMAGE, (uint8_t) Layer::PLATE, 2);
	Sprite *platedFoodSprites[5]	= { nullptr };
public:
	HandCombHud(Vector2 position);
	~HandCombHud();

	void AddPlatedFood(const PlatedFood *food);
	void ClearAllPlatedFood();

	void Update(float deltaTime) override;
};
