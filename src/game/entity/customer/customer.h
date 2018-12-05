#pragma once
#include <iostream>
#include <string>
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "game/entity/gameEntity.h"

class Customer : public GameEntity
{
private:

	AnimatedSprite *currentAnimSprite = nullptr;
	AnimatedSprite *leftAnimSprite = AnimatedSprite::Create(CUSTOMER_LEFT_IMAGE, 1, CUSTOMER_WIDTH, CUSTOMER_HEIGHT, CUSTOMER_ANIMATION_DELAY);
	AnimatedSprite *rightAnimSprite = AnimatedSprite::Create(CUSTOMER_RIGHT_IMAGE, 1, CUSTOMER_WIDTH, CUSTOMER_HEIGHT, CUSTOMER_ANIMATION_DELAY);
	float customerSpeed = 100.0f;

public:
	Customer();
	~Customer();
	
	void Update(float deltaTime) override;
	void Return(float deltaTime);
};