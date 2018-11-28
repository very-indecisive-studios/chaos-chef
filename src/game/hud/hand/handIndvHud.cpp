#include "handIndvHud.h"

HandIndvHud::HandIndvHud(Vector2 position)
	: Hud(position)
{ }

HandIndvHud::~HandIndvHud()
{
	delete foodSprite;
}

void HandIndvHud::SetPlatedFood(const PlatedFood *platedFood)
{
	this->platedFood = platedFood;

	delete foodSprite;
	foodSprite = Sprite::Create(platedFood->ingredient->textureName, (uint8_t)platedFood->layer, 2);
}

void HandIndvHud::RemovePlatedFood()
{
	this->platedFood = nullptr;

	delete foodSprite;
}

const PlatedFood * HandIndvHud::GetPlatedFood()
{
	return platedFood;
}

void HandIndvHud::Update(float deltaTime)
{
	if (foodSprite != nullptr)
	{
		foodSprite->Draw(position);
	}
}
