#pragma once
#include <iostream>
#include <string>
#include "../core/gameEntity.h"
#include "../core/animatedSprite.h"
#include "../game/resources.h"

namespace game
{
	class Player : public core::GameEntity
	{
		class PlayerAnimator *current;
	private:
		// core::GameEntityType type = PLAYER;
		UCHAR playerKeyUp = VK_UP;
		UCHAR playerKeyDown = VK_DOWN;
		UCHAR playerKeyLeft = VK_LEFT;
		UCHAR playerKeyRight = VK_RIGHT;
		int playerWidth = 32;
		int playerHeight = 32;
		float secPerFrame = 0.2f;

	public:
		Player();
		~Player();
		float playerSpeed = 100.0f;
		float velocity = 500.0f;
		float x;
		float y;

		core::AnimatedSprite *currentAnimSprite = NULL;
		core::AnimatedSprite *northAnimSprite = core::AnimatedSprite::Create(PLAYER_NORTH_IMAGE, playerWidth, playerHeight, secPerFrame);
		core::AnimatedSprite *eastAnimSprite = core::AnimatedSprite::Create(PLAYER_EAST_IMAGE, playerWidth, playerHeight, secPerFrame);
		core::AnimatedSprite *southAnimSprite = core::AnimatedSprite::Create(PLAYER_SOUTH_IMAGE, playerWidth, playerHeight, secPerFrame);
		core::AnimatedSprite *westAnimSprite = core::AnimatedSprite::Create(PLAYER_WEST_IMAGE, playerWidth, playerHeight, secPerFrame);

		void SetCurrent(PlayerAnimator *s) 
		{
			current = s;
		}
		void Move(float deltatime,core::AnimatedSprite *animSprite);

		void Update(float deltaTime);
		void Collided(GameEntity &gameEntity);
	};
}