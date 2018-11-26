#include <iostream>
#include "player.h"
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "core/math.h"
#include "context.h"

Player::Player() : GameEntity(GameEntityType::PLAYER) 
{
	x = 70;		// starting x
	y = 140;	// starting y
	currentAnimSprite = southAnimSprite; // starting direction
}

Player::~Player() 
{
	delete northAnimSprite;
	delete eastAnimSprite;
	delete southAnimSprite;
	delete westAnimSprite;
}

void Player::Move(float deltaTime, AnimatedSprite *animSprite)
{
	if (!Context::Get()->GetInputManager()->AnyKeyDown())
	{
		currentAnimSprite->Stop();
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown)) // SOUTH
	{
		if (currentAnimSprite != southAnimSprite)
		{
			currentAnimSprite = southAnimSprite;
		}
		else
		{
			y += deltaTime * playerSpeed;

			if (y >= (MAP_HEIGHT - animSprite->GetWidth())) // if off screen at bottom
			{
				y = MAP_HEIGHT - animSprite->GetWidth(); // position back to the bottom limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp)) // NORTH
	{
		if (currentAnimSprite != northAnimSprite)
		{
			currentAnimSprite = northAnimSprite;
		}
		else
		{
			y -= deltaTime * playerSpeed;

			if (y <= 0) // if off screen at top
			{
				y = 0; // position back to the top limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight)) // EAST
	{
		if (currentAnimSprite != eastAnimSprite)
		{
			currentAnimSprite = eastAnimSprite;
		}
		else
		{
			x += deltaTime * playerSpeed;

			if (x >= (MAP_WIDTH - animSprite->GetWidth())) // if off screen at right
			{
				x = MAP_WIDTH - animSprite->GetWidth(); // position back to the right limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft)) // WEST
	{
		if (currentAnimSprite != westAnimSprite)
		{
			currentAnimSprite = westAnimSprite;
		}
		else
		{
			x -= deltaTime * playerSpeed;

			if (x <= 0) // if off screen at left
			{
				x = 0; // position back to the left limit
			}
		}
	}

	animSprite->UpdateAndDraw(deltaTime, Vector2(x, y));
}

void Player::Update(float deltaTime)
{
	this->Move(deltaTime, currentAnimSprite);
	currentAnimSprite->Play();
}

void Player::Collided(GameEntity &gameEntity)
{

}