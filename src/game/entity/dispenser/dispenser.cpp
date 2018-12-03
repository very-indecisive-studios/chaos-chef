#include <string>
#include "dispenser.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

Dispenser::Dispenser() 
	: GameEntity(GameEntityType::DISPENSER)
{
	collisionBounds.topLeft		= Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(32, 32);
}

Dispenser::~Dispenser()
{
	delete ingreSprite;
}

const PlatedFood* Dispenser::GetPlatedFood()
{
	return platedFood;
}

void Dispenser::SetPlatedFood(const PlatedFood *platedFood)
{
	this->platedFood = platedFood;

	if (platedFood != nullptr)
	{
		ingreSprite = Sprite::Create(platedFood->ingredient->textureName, 0);
	}
}

bool Dispenser::IsActive() 
{
	return platedFood != nullptr;
}

void Dispenser::Update(float deltaTime)
{
	if (ingreSprite != nullptr)
	{
		ingreSprite->Draw(position);
	}
}