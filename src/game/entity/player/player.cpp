#include <iostream>
#include "player.h"
#include "game/entity/gameEntity.h"
#include "game/entity/dispenser/dispenserArea.h"
#include "core/sprites/animatedSprite.h"
#include "core/math.h"
#include "context.h"
#include "game/data/gameSceneData.h"

Player::Player()  
	: GameEntity(GameEntityType::PLAYER) 
{
	collisionBounds.topLeft		= Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(32, 32);

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
	// SOUTH == DOWN
	if (Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown))
	{
		if (currentAnimSprite != southAnimSprite) // changing direction of player
		{
			currentAnimSprite = southAnimSprite;
		}
		else
		{
			position.y += deltaTime * playerSpeed;

			if (position.y >= (GameSceneData::Map::BOUNDS.bottomRight.y - currentAnimSprite->GetHeight())) // if off screen at bottom
			{
				position.y = GameSceneData::Map::BOUNDS.bottomRight.y - currentAnimSprite->GetHeight(); // position back to the bottom limit
			}
		}

		currentAnimSprite->Play();
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

			if (position.y <= GameSceneData::Map::BOUNDS.topLeft.y) // if off screen at top
			{
				position.y = GameSceneData::Map::BOUNDS.topLeft.y; // position back to the top limit
			}
		}

		currentAnimSprite->Play();
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
			if (position.x >= (GameSceneData::Map::BOUNDS.bottomRight.x - currentAnimSprite->GetWidth())) // if off screen at right
			{
				position.x = GameSceneData::Map::BOUNDS.bottomRight.x - currentAnimSprite->GetWidth(); // position back to the right limit
			}
		}

		currentAnimSprite->Play();
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
			if (position.x <= GameSceneData::Map::BOUNDS.topLeft.x) // if off screen at left
			{
				position.x = GameSceneData::Map::BOUNDS.topLeft.x; // position back to the left limit
			}
		}

		currentAnimSprite->Play();
	}
	else // if movement keys are not pressed
	{
		currentAnimSprite->Stop();
	}
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);

	currentAnimSprite->UpdateAndDraw(deltaTime, position);

	hand.Update(deltaTime, position);
}

void Player::HandleCollision(GameEntity *entity)
{
	//std::cout << "player - x: " << position.x << " y :" << position.y << std::endl;
	//std::cout << "entity - x: " << entity->GetPosition().x << " y :" << entity->GetPosition().y << std::endl;
	if (
		entity->GetType() == GameEntityType::DISPENSER ||
		entity->GetType() == GameEntityType::PROP
	)
	{
		std::cout << "PROP/DISPENSER" << std::endl;
		BlockPlayer(entity);
	}
	else if (entity->GetType() == GameEntityType::DISPENSER_AREA) // area around DISPENSER - get food with actionKey
	{
		std::cout << "DISPENSER AREA" << std::endl;

		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			GetPlatedFood(entity);
			std::cout << "GET FOOD" << std::endl;
		}
	}
	else if (entity->GetType() == GameEntityType::TRASH_BIN_AREA) // remove food on action_button
	{
		std::cout << "TRASH BIN AREA" << std::endl;

		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "REMOVE FOOD" << std::endl;
		}
	}
	else if (entity->GetType() == GameEntityType::COUNTER_AREA) // area around COUNTER - if dish-on-hand == order, give dish}
	{
		if (Context::Get()->GetInputManager()->IsKeyDown(actionKey))
		{
			std::cout << "GIVE FOOD" << std::endl;
		}
	}
	else if (entity->GetType() == GameEntityType::VEHICLE) // GAME OVER scene
	{
		Context::Get()->GetSceneManager()->LoadLeaderboardScene(true);
	}
}

void Player::BlockPlayer(GameEntity *entity) // Move player back to their original spot
{
	if (currentAnimSprite == northAnimSprite)
	{
		position.y = entity->GetPosition().y + entity->GetCollisionBounds().bottomRight.y + 0.1f;
	}
	else if (currentAnimSprite == southAnimSprite)
	{
		position.y = entity->GetPosition().y - currentAnimSprite->GetWidth() - 0.1f;
	}
	else if (currentAnimSprite == westAnimSprite)
	{
		position.x = entity->GetPosition().x + entity->GetCollisionBounds().bottomRight.x + 0.1f;
	}
	else if (currentAnimSprite == eastAnimSprite)
	{
		position.x = entity->GetPosition().x - currentAnimSprite->GetHeight() - 0.1f;
	}
}

void Player::GetPlatedFood(GameEntity *entity) // Move player back to their original spot
{
	DispenserArea *currentDispenserArea = (DispenserArea *)entity;
	Dispenser *currentDispenser = currentDispenserArea->GetDispenser();

	if (currentDispenser->IsActive()) 
	{
		const PlatedFood *platedFood = currentDispenser->GetPlatedFood();

		hand.Add(platedFood);
	}
}