#pragma once

#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"


class Player : public GameEntity
{
	class PlayerAnimator *current;
private:
	UCHAR playerKeyUp = VK_UP;
	UCHAR playerKeyDown = VK_DOWN;
	UCHAR playerKeyLeft = VK_LEFT;
	UCHAR playerKeyRight = VK_RIGHT;

public:
	Player();
	~Player();
	float playerSpeed = 100.0f;
	float velocity = 500.0f;
	float x;
	float y;

	AnimatedSprite *currentAnimSprite	= nullptr;
	AnimatedSprite *northAnimSprite		= AnimatedSprite::Create(PLAYER_NORTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *eastAnimSprite		= AnimatedSprite::Create(PLAYER_EAST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *southAnimSprite		= AnimatedSprite::Create(PLAYER_SOUTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *westAnimSprite		= AnimatedSprite::Create(PLAYER_WEST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);

	void SetCurrent(PlayerAnimator *s) 
	{
		current = s;
	}
	void Move(float deltatime, AnimatedSprite *animSprite);

	void Update(float deltaTime) override;
	void Collided(GameEntity &gameEntity) override;
};