#include "handCombHud.h"
#include <iostream>
#include "game/data/gameSceneData.h"

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
			s = Sprite::Create(food->textureName, food->layer, 2);
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
	plateSprite->Draw(position + GameSceneData::Hud::Top::HAND_COMB_HUD_PF_REL_LOCATION);
	
	for (Sprite *&s : platedFoodSprites)
	{
		if (s != nullptr)
		{
			s->Draw(position + GameSceneData::Hud::Top::HAND_COMB_HUD_PF_REL_LOCATION);
		}
	}
}
