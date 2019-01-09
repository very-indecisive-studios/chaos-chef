#pragma once
#include <iostream>
#include <string>
#include "core/sprites/animatedSprite.h"
#include "game/resources.h"
#include "playerHand.h"
#include "game/entity/gameEntity.h"
#include "core/audio/audio.h"

class Player : public GameEntity
{
private:
	UCHAR playerKeyUp = VK_UP;
	UCHAR playerKeyDown = VK_DOWN;
	UCHAR playerKeyLeft = VK_LEFT;
	UCHAR playerKeyRight = VK_RIGHT;
	UCHAR actionKey = VK_SPACE;


	AnimatedSprite *currentAnimSprite = nullptr;
	AnimatedSprite *northAnimSprite = AnimatedSprite::Create(PLAYER_NORTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *eastAnimSprite = AnimatedSprite::Create(PLAYER_EAST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *southAnimSprite = AnimatedSprite::Create(PLAYER_SOUTH_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *westAnimSprite = AnimatedSprite::Create(PLAYER_WEST_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);
	AnimatedSprite *deadAnimSprite = AnimatedSprite::Create(PLAYER_DEAD_IMAGE, 1, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_ANIMATION_DELAY);

	AudioPlayer *splatSoundPlayer;
	AudioPlayer *deathSoundPlayer;

	PlayerHand hand;
	bool playerDead = false;
	float playerSpeed = 200.0f;

	void Move(float deltatime);

	void GetPlatedFood(GameEntity *entity);
	void BlockPlayer(GameEntity *entity);
public:
	Player();
	~Player();

	UCHAR GetActionKey() { return actionKey; }
	std::vector<const PlatedFood *> Give();

	void HandleCollision(GameEntity *entity) override;
	bool isDead();
	void Update(float deltaTime) override;
};
