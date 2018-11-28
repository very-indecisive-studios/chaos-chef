#pragma once
#include <iostream>
#include <string>
#include "gameEntity.h"
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "playerHand.h"

class Player : public GameEntity
{
private:
	UCHAR playerKeyUp = VK_UP;
	UCHAR playerKeyDown = VK_DOWN;
	UCHAR playerKeyLeft = VK_LEFT;
	UCHAR playerKeyRight = VK_RIGHT;
	UCHAR actionKey = VK_SPACE;

	float playerSpeed = 200.0f;

	AnimatedSprite *currentAnimSprite = nullptr;
	AnimatedSprite *northAnimSprite = AnimatedSprite::Create(PLAYER_NORTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *eastAnimSprite = AnimatedSprite::Create(PLAYER_EAST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *southAnimSprite = AnimatedSprite::Create(PLAYER_SOUTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *westAnimSprite = AnimatedSprite::Create(PLAYER_WEST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);

	Sprite *platedFoodImage1;
	Sprite *platedFoodImage2;
	Sprite *platedFoodImage3;
	Sprite *platedFoodImage4;
	Sprite *platedFoodImage5;

	PlayerHand hand;

	void DrawPlateFood();
	void Move(float deltatime);
public:
	Player();
	~Player();
	std::vector<const PlatedFood *> GetOnPlate() { return onPlate; }
	UCHAR GetActionKey() { return actionKey; }
	void SetOnPlate(const PlatedFood *platedFood) { onPlate.push_back(platedFood); }
	void GetPlatedFood(GameEntity *entity);
	void BlockPlayer(float deltaTime);
	void HandleCollision(float deltaTime, GameEntity *entity);

	void Update(float deltaTime) override;
};
