#include <iostream>
#include "customer.h"
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "core/math.h"
#include "context.h"
#include "game/data/gameSceneData.h"

Customer::Customer(): GameEntity(GameEntityType::CUSTOMER)
{
	currentAnimSprite = leftAnimSprite;
}

Customer::~Customer()
{
	delete leftAnimSprite;
	delete rightAnimSprite;
}

void Customer::Update(float deltaTime) 
{
	position.x -= deltaTime * customerSpeed;
	currentAnimSprite->UpdateAndDraw(deltaTime, position);
}

void Customer::Return(float deltaTime)
{
	currentAnimSprite = rightAnimSprite;
	position.x += deltaTime * customerSpeed;
	currentAnimSprite->UpdateAndDraw(deltaTime, position);
}