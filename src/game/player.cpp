#include <iostream>
#include "player.h"
#include "game/entity/gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "core/math.h"
#include "context.h"

Player::Player() : GameEntity(GameEntityType::PLAYER) 
{
	position.x = 70;		// starting x
	position.y = 140;	// starting y
	currentAnimSprite = southAnimSprite; // starting direction
}

Player::~Player() 
{
	delete northAnimSprite;
	delete eastAnimSprite;
	delete southAnimSprite;
	delete westAnimSprite;
}

void Player::Move(float deltaTime)
{
	if (!Context::Get()->GetInputManager()->AnyKeyDown())
	{
		currentAnimSprite->Stop();
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown)) // SOUTH
	{
		if (currentAnimSprite != southAnimSprite)
		{
			currentAnimSprite->Stop();
			currentAnimSprite = southAnimSprite;
		}
		else
		{
			position.y += deltaTime * playerSpeed;

			if (position.y >= (MAP_HEIGHT - currentAnimSprite->GetWidth())) // if off screen at bottom
			{
				position.y = MAP_HEIGHT - currentAnimSprite->GetWidth(); // position back to the bottom limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp)) // NORTH
	{
		if (currentAnimSprite != northAnimSprite)
		{
			currentAnimSprite->Stop();
			currentAnimSprite = northAnimSprite;
		}
		else
		{
			position.y -= deltaTime * playerSpeed;

			if (position.y <= 0) // if off screen at top
			{
				position.y = 0; // position back to the top limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight)) // EAST
	{
		if (currentAnimSprite != eastAnimSprite)
		{
			currentAnimSprite->Stop();
			currentAnimSprite = eastAnimSprite;
		}
		else
		{
			position.x += deltaTime * playerSpeed;

			if (position.x >= (MAP_WIDTH - currentAnimSprite->GetWidth())) // if off screen at right
			{
				position.x = MAP_WIDTH - currentAnimSprite->GetWidth(); // position back to the right limit
			}
		}
	}
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft)) // WEST
	{
		if (currentAnimSprite != westAnimSprite)
		{
			currentAnimSprite->Stop();
			currentAnimSprite = westAnimSprite;
		}
		else
		{
			position.x -= deltaTime * playerSpeed;

			if (position.x <= 0) // if off screen at left
			{
				position.x = 0; // position back to the left limit
			}
		}
	}

	currentAnimSprite->Play();
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);

	currentAnimSprite->UpdateAndDraw(deltaTime, position);
}

void Player::Collided(GameEntity &gameEntity)
{

}