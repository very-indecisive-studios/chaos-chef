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
	if (!Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown) 
		&& !Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp) 
		&& !Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft) 
		&& !Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight)) // if movement keys are not pressed
	{
		currentAnimSprite->Stop();
	}
	// SOUTH == DOWN
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown))
	{
		if (currentAnimSprite != southAnimSprite) // changing direction of player
		{
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
	// NORTH == UP
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp))
	{
		if (currentAnimSprite != northAnimSprite)
		{
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
	// EAST == RIGHT
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight))
	{
		if (currentAnimSprite != eastAnimSprite)
		{
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
	// WEST == LEFT
	else if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft))
	{
		if (currentAnimSprite != westAnimSprite)
		{
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

	if (entity->GetType() == GameEntityType::DISPENSER) { BlockPlayer(deltaTime); } // block player from actual solid DISPENSER
	else if (entity->GetType() == GameEntityType::DISPENSER_AREA) // area around DISPENSER - get food with actionKey
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "Collected Food"  << std::endl;
		}
	}

	else if (entity->GetType() == GameEntityType::TRASH_BIN) { BlockPlayer(deltaTime); } // block player from actual solid TRASH_BIN
	else if (entity->GetType() == GameEntityType::TRASH_BIN_AREA) // remove food on action_button
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "REMOVE FOOD" << std::endl;
		}
	}

	else if (entity->GetType() == GameEntityType::COUNTER) { BlockPlayer(deltaTime); } // block player from actual solid COUNTER
	else if (entity->GetType() == GameEntityType::COUNTER_AREA) // area around COUNTER - if dish-on-hand == order, give dish}
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "GIVE FOOD" << std::endl;
		}
	}

	else if (entity->GetType() == GameEntityType::VEHICLE)
	{
		//GAME OVER scene
	}
}

void Player::BlockPlayer(float deltaTime) // Move player back to their original spot
{
	if (currentAnimSprite == northAnimSprite)
	{
		position.y += deltaTime * playerSpeed;
	}
	else if (currentAnimSprite == eastAnimSprite)
	{
		position.x -= deltaTime * playerSpeed;
	}
	else if (currentAnimSprite == southAnimSprite)
	{
		position.y -= deltaTime * playerSpeed;
	}
	else if (currentAnimSprite == westAnimSprite)
	{
		position.x += deltaTime * playerSpeed;
	}
}