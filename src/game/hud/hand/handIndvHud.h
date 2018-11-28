#pragma once
#include "game/hud/order/orderHud.h"

class HandIndvHud : public Hud
{
private:
	const PlatedFood *platedFood = nullptr;
	Sprite *foodSprite = nullptr;
public:
	HandIndvHud(Vector2 position);
	~HandIndvHud();

	void SetPlatedFood(const PlatedFood * platedFood);
	void RemovePlatedFood();
	const PlatedFood * GetPlatedFood();

	void Update(float deltaTime) override;
};
