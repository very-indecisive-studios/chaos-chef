#include "handCombHud.h"
#include <iostream>

HandCombHud::HandCombHud(Vector2 position)
	: Hud(position)
{ }

HandCombHud::~HandCombHud()
{
	delete plateSprite;

	ClearAllPlatedFood();
}

void HandCombHud::AddPlatedFood(const PlatedFood * food)
{
	for (Sprite *&s : platedFoodSprites)
	{
		if (s == nullptr)
		{
			s = Sprite::Create(food->textureName, (uint8_t)food->layer, 2);
			break;
		}
	}
}

void HandCombHud::ClearAllPlatedFood()
{
	for (Sprite *s : platedFoodSprites)
	{
		delete s;
	}
}

void HandCombHud::Update(float deltaTime)
{
	plateSprite->Draw(position + relPlatePosition);
	
	for (Sprite *&s : platedFoodSprites)
	{
		if (s != nullptr)
		{
			s->Draw(position + relPlatePosition);
		}
	}
}
