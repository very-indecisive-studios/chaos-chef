#include "playerHand.h"

PlayerHand::PlayerHand()
{ }

PlayerHand::~PlayerHand()
{
	// Delete all sprites.
	for (Sprite *s : foodsOnPlateSprites)
	{
		delete s;
	}
	foodsOnPlateSprites.clear();
}

void PlayerHand::AddPlatedFoodToHuds(const PlatedFood * platedFood)
{
	handCombHud.AddPlatedFood(platedFood);
	for (HandIndvHud &hud : handIndvHuds)
	{
		if (hud.GetPlatedFood() == nullptr)
		{
			hud.SetPlatedFood(platedFood);
			break;
		}
	}
}

void PlayerHand::ResetHuds()
{
	handCombHud.ClearAllPlatedFood();
	for (HandIndvHud &hud : handIndvHuds)
	{
		hud.RemovePlatedFood();
	}
}


void PlayerHand::Add(const PlatedFood *platedFood)
{
	// Reject if > 5.
	if (foodsOnPlate.size() == MAX_PLATED_FOODS)
	{
		return;
	}

	for (const PlatedFood *pF : foodsOnPlate)
	{
		// Reject if same food.
		if (pF == platedFood)
		{
			return;
		}
	}

	foodsOnPlate.push_back(platedFood);
	AddPlatedFoodToHuds(platedFood);

	foodsOnPlateSprites.push_back(Sprite::Create(platedFood->textureName, platedFood->layer));
}

void PlayerHand::Empty()
{
	// Remove all foods.
	foodsOnPlate.clear();

	// Delete all sprites.
	for (Sprite *s : foodsOnPlateSprites)
	{
		delete s;
	}
	foodsOnPlateSprites.clear();

	// Reset HUDs.
	ResetHuds();
}

void PlayerHand::Update(float deltaTime, Vector2 playerPosition)
{
	// Update HUDs.
	handCombHud.Update(deltaTime);
	for (HandIndvHud &hud : handIndvHuds)
	{
		hud.Update(deltaTime);
	}

	// Draw all food sprites on player.
	for (Sprite *s : foodsOnPlateSprites)
	{
		s->Draw(playerPosition);
	}
}

std::vector<const PlatedFood *> PlayerHand::GetPlatedFood()
{
	return foodsOnPlate;
}
