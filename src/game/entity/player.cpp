#include <iostream>
#include "player.h"
#include "gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "core/math.h"
#include "context.h"

Player::Player() : GameEntity(GameEntityType::PLAYER) 
{
	collisionBounds.topLeft = Vector2(0,0);
	collisionBounds.bottomRight = Vector2(32,32); 
	position.x = 70;	// starting x
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
	if (!Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown) && !Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp) && !Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft) && !Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight))
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
			// (MAP_WIDTH - 95 ): for counter
			if (position.x >= ((MAP_WIDTH - 95 ) - currentAnimSprite->GetWidth())) // if off screen at right
			{
				position.x = (MAP_WIDTH - 95) - currentAnimSprite->GetWidth(); // position back to the right limit
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
			// 32: for dispensers
			if (position.x <= 32) // if off screen at left
			{
				position.x = 32; // position back to the left limit
			}
		}
	}
	currentAnimSprite->UpdateAndDraw(deltaTime, position);
	std::cout << "x: " << position.x << " y: " << position.y << std::endl;
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);
	currentAnimSprite->Play();
}

void Player::HandleCollision(float deltaTime, GameEntity *entity)
{
	CollisionBounds entityCollisionBounds = entity->GetCollisionBounds();
	Vector2 entityPosition = entity->GetPosition();

	if (entity->GetType() == GameEntityType::DISPENSER) // area around DISPENSER - get food with actionKey
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "GOT FOOD" << std::endl;
		}
	}
	else if (entity->GetType() == GameEntityType::TRASH_BIN)
	{
		//block player
	}
	else if (entity->GetType() == GameEntityType::TRASH_BIN_AREA)
	{
		//remove food on action_button
	}
	else if (entity->GetType() == GameEntityType::COUNTER)
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "GIVE FOOD" << std::endl;
		}
		
		//if dish-on-hand == order {give dish}
	}
	else if (entity->GetType() == GameEntityType::VEHICLE)
	{
		//GAME OVER scene
	}
}