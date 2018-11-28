#pragma once

#include "game/hud/hud.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/data/food.h"
#include "game/data/spriteLayer.h"

class HandCombHud : public Hud
{
private:
	const Vector2 relPlatePosition = Vector2(0, 16);

	Sprite *plateSprite				= Sprite::Create(EMPTY_PLATE_IMAGE, (uint8_t) SpriteLayer::PLATE, 2);
	Sprite *platedFoodSprites[5]	= { nullptr };
public:
	HandCombHud(Vector2 position);
	~HandCombHud();

	void AddPlatedFood(const PlatedFood *food);
	void ClearAllPlatedFood();

	void Update(float deltaTime) override;
};
