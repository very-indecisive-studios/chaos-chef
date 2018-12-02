#pragma once

#include <vector>
#include "game/resources.h"
#include "game/gameplay/order/order.h"
#include "core/sprites/animatedSprite.h"
#include "game/hud/hud.h"
#include "game/data/gameSceneData.h"

class OrderHud : public Hud
{
private:
	Order *order = nullptr;
	
	Sprite *plateSprite = Sprite::Create(EMPTY_PLATE_IMAGE, Layer::PLATE, GameSceneData::Hud::Bottom::ORDER_HUD_PF_SCALE);
	std::vector<Sprite *> platedFoodSprites;
	std::vector<Sprite *> ingreSprites;

	void InitSprites();
	void ClearSprites();
public:
	OrderHud(Vector2 position);
	~OrderHud();

	void Update(float deltaTime) override;

	void SetOrder(Order *order);
	Order * GetOrder();
};
