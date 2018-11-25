#pragma once

#include "scene.h"
#include "game/player.h"
#include "core/sprites/sprite.h"

class GameScene : public Scene
{
private:
	Player *player;
	Sprite *map;
	
	void CheckCollisions();
public:
	GameScene();
	~GameScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
