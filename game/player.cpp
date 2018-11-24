#include "player.h"
#include "../core/animatedSprite.h"
#include "../core/context.h"
#include "../core/math.h"
#include <iostream>

game::Player::Player():GameEntity(core::GameEntityType::PLAYER) 
{
	x = 0;
	y = 0;
	changeOfX = 0;
	changeOfY = 0;
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
		changeOfY += velocity;
		y += (deltaTime * (playerSpeed + changeOfY));

		if (y >= (360/*REMINDER TO CHANGE TO GAME_HEIGHT*/ - animSprite->GetWidth())) // if off screen at bottom
		{
			y = 360 /*REMINDER TO CHANGE TO GAME_HEIGHT*/ - animSprite->GetWidth(); // position back to the bottom limit
			changeOfY -= velocity; // reseting value, else math error
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyUp))
	{
		currentAnimSprite = northAnimSprite;
		changeOfY -= velocity;
		y -= (deltaTime * (playerSpeed + changeOfY));
		if (y <= 0) // if off screen at top
		{
			y = 0; // position back to the top limit
			changeOfY += velocity; // reseting value, else math error
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyRight))
	{
		currentAnimSprite = eastAnimSprite;
		changeOfX += velocity;
		x += deltaTime * (playerSpeed + changeOfX);
		if (x >= (640/*REMINDER TO CHANGE TO GAME_WIDTH*/  - animSprite->GetWidth())) // if off screen at right
		{
			x = 640 /*REMINDER TO CHANGE TO GAME_WIDTH*/ - animSprite->GetWidth(); // position back to the right limit
			changeOfX -= velocity; // reseting value, else math error
		}
	}
	else if (core::Context::Get()->GetInputManager()->IsKeyDown(playerKeyLeft))
	{
		currentAnimSprite = westAnimSprite;
		changeOfX -= velocity;
		x -= deltaTime * (playerSpeed + changeOfX);
		if (x <= 0) // if off screen at left
		{
			x = 0; // position back to the left limit
			changeOfX += velocity; // reseting value, else math error
		}
	}

	//std::cout << "x: " << x << " y: " << y << "\n";
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