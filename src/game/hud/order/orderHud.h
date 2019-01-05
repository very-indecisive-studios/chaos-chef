#pragma once

#include <vector>
#include "game/resources.h"
#include "game/gameplay/order/order.h"
#include "core/sprites/animatedSprite.h"
#include "game/hud/hud.h"
#include "game/data/gameSceneData.h"
#include "core/text/text.h"

class OrderHud : public Hud
{
private:
	Order *order = nullptr;
	
	Sprite *plateSprite = Sprite::Create(EMPTY_PLATE_IMAGE, Layer::PLATE, GameSceneData::Hud::Bottom::ORDER_HUD_PF_SCALE);
	Text   *timerText = Text::Create("0:00", FONT_TYPE, FONT_COLOR_BLACK, 16, 100, false, false, DT_LEFT);
	std::vector<Sprite *> platedFoodSprites;
	std::vector<Sprite *> ingreSprites;

	void InitSprites();
	void ClearSprites();
public:
	OrderHud(Vector2 position);
	~OrderHud();

	void Update(float deltaTime) override;

	void SetOrder(Order *order);
	void ClearOrder();
	Order * GetOrder();
};
