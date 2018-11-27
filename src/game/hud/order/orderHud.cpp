#include "orderHud.h"

OrderHud::OrderHud(Vector2 position)
	: Hud(position)
{ }

OrderHud::~OrderHud()
{
	ClearFoodSprites();

	// Don't delete order. OrderManager will handle the deletion.
}

void OrderHud::Update(float deltaTime)
{
	plateSprite->Draw(position + relPlatePosition);

	for (Sprite *foodSprite : foodSprites)
	{
		foodSprite->Draw(position + relPlatePosition);
	}
}

void OrderHud::SetOrder(Order * order)
{
	this->order = order;

	ClearFoodSprites();
	InitFoodSprites();
}

Order * OrderHud::GetOrder()
{
	return this->order;
}

void OrderHud::InitFoodSprites()
{
	for (const PlatedFood *pF : this->order->meal->foods)
	{
		Sprite *pFSprite = Sprite::Create(pF->textureName, (uint8_t) pF->layer, 3);

		foodSprites.push_back(pFSprite);
	}
}

void OrderHud::ClearFoodSprites()
{
	for (Sprite *foodSprite : foodSprites)
	{
		delete foodSprite;
	}

	foodSprites.clear();
}
