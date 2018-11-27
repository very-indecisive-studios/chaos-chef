#include <string>
#include "dispenser.h"
#include "gameEntity.h"
#include "core/math.h"

Dispenser::Dispenser() : GameEntity(GameEntityType::DISPENSER){}

Dispenser::~Dispenser() {}

const PlatedFood *Dispenser::GetIngredient() { return platedFood; }

void Dispenser::SetIngredient(const PlatedFood *inputPlatedFood) { platedFood = inputPlatedFood; }

bool Dispenser::IsActive() 
{
	if (platedFood != NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Sprite *Dispenser::GetImage() { return platedFoodImage; }

void Dispenser::SetImage()
{
	platedFoodImage = Sprite::Create(platedFood->textureName, 0); 
}

void Dispenser::Update(float deltaTime){}