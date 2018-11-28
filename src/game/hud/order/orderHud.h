#pragma once

#include <vector>
#include "game/resources.h"
#include "game/gameplay/order/order.h"
#include "core/sprites/animatedSprite.h"
#include "game/hud/hud.h"

class OrderHud : public Hud
{
private:
	Order *order = nullptr;
	
	Sprite *plateSprite = Sprite::Create(EMPTY_PLATE_IMAGE, (uint8_t) SpriteLayer::PLATE, 3);
	std::vector<Sprite *> foodSprites;

	const Vector2 relPlatePosition = Vector2(32, 0);

	void InitFoodSprites();
	void ClearFoodSprites();
public:
	OrderHud(Vector2 position);
	~OrderHud();

	void Update(float deltaTime) override;

	void SetOrder(Order *order);
	Order * GetOrder();
};
