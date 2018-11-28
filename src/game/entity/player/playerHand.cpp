#include "playerHand.h"

PlayerHand::PlayerHand()
{ }

PlayerHand::~PlayerHand()
{ }

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
	const PlatedFood **freePlatedFood = nullptr;

	for (const PlatedFood *&pF : foodsOnPlate)
	{
		// Reject if same food.
		if (pF == platedFood)
		{
			return;
		}

		// Get pointer address in array that has not been assigned.
		if (pF == nullptr)
		{
			freePlatedFood = &pF;
		}
	}

	// Assign the plated food to a free space in array.
	if (freePlatedFood != nullptr)
	{
		*freePlatedFood = platedFood;

		AddPlatedFoodToHuds(platedFood);
	}
}

void PlayerHand::Empty()
{
	for (const PlatedFood *&pF : foodsOnPlate)
	{
		pF = nullptr;
	}

	ResetHuds();
}

void PlayerHand::Update(float deltaTime)
{
	handCombHud.Update(deltaTime);
	for (HandIndvHud &hud : handIndvHuds)
	{
		hud.Update(deltaTime);
	}
}
