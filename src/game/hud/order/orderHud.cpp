#include "orderHud.h"
#include "game/data/gameSceneData.h"

OrderHud::OrderHud(Vector2 position)
	: Hud(position)
{ }

OrderHud::~OrderHud()
{
	delete plateSprite;
	
	ClearSprites();

	delete timerText;

	// Don't delete order. OrderManager will handle the deletion.
}

void OrderHud::Update(float deltaTime)
{
	if (order != nullptr)
	{
		plateSprite->Draw(position + GameSceneData::Hud::Bottom::ORDER_HUD_PF_REL_LOCATION);

		for (Sprite *foodSprite : platedFoodSprites)
		{
			foodSprite->Draw(position + GameSceneData::Hud::Bottom::ORDER_HUD_PF_REL_LOCATION);
		}

		auto ingreSpritesIt = ingreSprites.begin();
		for (const Vector2 &ingreSpriteLocation : GameSceneData::Hud::Bottom::ORDER_HUD_ING_REL_LOCATIONS)
		{
			// End of vector.
			if (ingreSpritesIt == ingreSprites.end())
			{
				break;
			}

			(*ingreSpritesIt)->Draw(position + ingreSpriteLocation);

			// Increment vector iterator.
			++ingreSpritesIt;
		}
		
		int minutes = (int) order->timeRemainingSeconds / 60;
		int seconds = (int) order->timeRemainingSeconds % 60;
		std::string timeString = std::to_string(minutes) + ":" + (seconds >= 10 ? std::to_string(seconds) : "0" + std::to_string(seconds));
		timerText->SetText(timeString);

		timerText->Draw(position + GameSceneData::Hud::Bottom::ORDER_HUD_TIME_REL_LOCATION);
	}
}

void OrderHud::SetOrder(Order * order)
{
	this->order = order;

	ClearSprites();
	InitSprites();
}

void OrderHud::ClearOrder()
{
	this->order == nullptr;

	ClearSprites();
}

Order * OrderHud::GetOrder()
{
	return this->order;
}

void OrderHud::InitSprites()
{
	for (const PlatedFood *pF : this->order->meal->foods)
	{
		Sprite *pFSprite	= Sprite::Create(pF->textureName, pF->layer, GameSceneData::Hud::Bottom::ORDER_HUD_PF_SCALE);
		Sprite *ingreSprite = Sprite::Create(pF->ingredient->textureName, Layer::FOOD_1, GameSceneData::Hud::Bottom::ORDER_HUD_IG_SCALE);

		platedFoodSprites.push_back(pFSprite);
		ingreSprites.push_back(ingreSprite);
	}
}

void OrderHud::ClearSprites()
{
	for (Sprite *pFoodSprite : platedFoodSprites)
	{
		delete pFoodSprite;
	}
	platedFoodSprites.clear();

	for (Sprite *ingreSprite : ingreSprites)
	{
		delete ingreSprite;
	}
	ingreSprites.clear();
}
