#include "player.h"
#include "../core/animatedSprite.h"
#include "../core/context.h"
#include "../core/math.h"
#include <iostream>

/*REMINDER TO CHANGE 360 TO GAME_HEIGHT*/
/*REMINDER TO CHANGE 640 TO GAME_WIDTH*/

game::Player::Player():GameEntity(core::GameEntityType::PLAYER) 
{
	x = 0;
	y = 0;
	currentAnimSprite = southAnimSprite;
}

game::Player::~Player() {}

void game::Player::Move(float deltaTime, core::AnimatedSprite *animSprite)
{
	if (!core::Context::Get()->GetInputManager()->AnyKeyPressed())
	{
		//std::cout << "no key pressed\n";
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyDown)) 
	{
		currentAnimSprite = southAnimSprite;
		y += (deltaTime * (playerSpeed + velocity));

		if (y >= (360- animSprite->GetWidth())) // if off screen at bottom
		{
			y = 360 - animSprite->GetWidth(); // position back to the bottom limit
		}
		std::cout << "GOING DOWN " << "x: " << x << " y: " << y << "\n";
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp))
	{
		currentAnimSprite = northAnimSprite;
		y -= (deltaTime * (playerSpeed + velocity));
		if (y <= 0) // if off screen at top
		{
			y = 0; // position back to the top limit
		}
		std::cout << "GOING UP " << "x: " << x << " y: " << y << "\n";
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight))
	{
		currentAnimSprite = eastAnimSprite;
		x += deltaTime * (playerSpeed + velocity);
		if (x >= (640 - animSprite->GetWidth())) // if off screen at right
		{
			x = 640 - animSprite->GetWidth(); // position back to the right limit
		}
		std::cout << "GOING RIGHT " << "x: " << x << " y: " << y << " deltatime: "<< deltaTime << "\n";
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft))
	{
		currentAnimSprite = westAnimSprite;
		x -= deltaTime * (playerSpeed + velocity);
		if (x <= 0) // if off screen at left
		{
			x = 0; // position back to the left limit
		}
		std::cout << "GOING LEFT " << "x: " << x << " y: " << y <<  "\n" ;
	}

	
	animSprite->UpdateAndDraw(deltaTime, core::Vector2(x, y));
}

void game::Player::Update(float deltaTime)
{
	currentAnimSprite->Play();
	this->Move(deltaTime, currentAnimSprite);
}

void game::Player::Collided(core::GameEntity &gameEntity)
{

}