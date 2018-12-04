#include "handIndvHud.h"
#include "game/data/gameSceneData.h"

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
	foodSprite = Sprite::Create(platedFood->ingredient->textureName, platedFood->layer, GameSceneData::Hud::Top::HAND_INDV_HUD_ING_SCALE);
}

void HandIndvHud::RemovePlatedFood()
{
	this->platedFood = nullptr;

	if (foodSprite != nullptr)
	{
		delete foodSprite;
		foodSprite = nullptr;
	}
}

const PlatedFood * HandIndvHud::GetPlatedFood()
{
	return platedFood;
}

void HandIndvHud::Update(float deltaTime)
{
	if (foodSprite != nullptr)
	{
		foodSprite->Draw(position + GameSceneData::Hud::Top::HAND_INDV_HUD_ING_REL_LOCATION);
	}
}
