#include "player.h"
#include "../core/animatedSprite.h"
#include "../core/context.h"
#include "../core/math.h"
#include <iostream>

/*REMINDER TO CHANGE 360 TO GAME_HEIGHT*/
/*REMINDER TO CHANGE 640 TO GAME_WIDTH*/

game::Player::Player():GameEntity(core::GameEntityType::PLAYER) 
{
	x = 70;		// starting x
	y = 140;	// starting y
	currentAnimSprite = southAnimSprite; // starting direction
}

game::Player::~Player() 
{
	delete currentAnimSprite;
	delete northAnimSprite;
	delete eastAnimSprite;
	delete southAnimSprite;
	delete westAnimSprite;
}

void game::Player::Move(float deltaTime, core::AnimatedSprite *animSprite)
{
	if (!core::Context::Get()->GetInputManager()->AnyKeyPressed())
	{
		currentAnimSprite->Stop();
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown)) // SOUTH
	{
		currentAnimSprite = southAnimSprite;
		y += (deltaTime * (playerSpeed + velocity));
		if (y >= (360- animSprite->GetWidth())) // if off screen at bottom
		{
			y = 360 - animSprite->GetWidth(); // position back to the bottom limit
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp)) // NORTH
	{
		currentAnimSprite = northAnimSprite;
		y -= (deltaTime * (playerSpeed + velocity));
		if (y <= 0) // if off screen at top
		{
			y = 0; // position back to the top limit
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight)) // EAST
	{
		currentAnimSprite = eastAnimSprite;
		x += deltaTime * (playerSpeed + velocity);
		if (x >= (640 - animSprite->GetWidth())) // if off screen at right
		{
			x = 640 - animSprite->GetWidth(); // position back to the right limit
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft)) // WEST
	{
		currentAnimSprite = westAnimSprite;
		x -= deltaTime * (playerSpeed + velocity);
		if (x <= 0) // if off screen at left
		{
			x = 0; // position back to the left limit
		}
	}

	animSprite->UpdateAndDraw(deltaTime, core::Vector2(x, y));
}

void game::Player::Update(float deltaTime)
{
	this->Move(deltaTime, currentAnimSprite);
	currentAnimSprite->Play();
}

void game::Player::Collided(core::GameEntity &gameEntity)
{

}