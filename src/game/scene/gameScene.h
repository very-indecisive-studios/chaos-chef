#pragma once

#include "scene.h"
#include "game/entity/player.h"
#include "game/entity/dispenser.h"
#include "game/entity/counter.h"
#include "core/sprites/sprite.h"

class GameScene : public Scene
{
private:
	Player *player;
	Sprite *map;
	Dispenser *dispenser1;
	Dispenser *dispenser2;
	Dispenser *dispenser3;
	Dispenser *dispenser4;
	Dispenser *dispenser5;

	Counter *counter1;
	Counter *counter2;
	Counter *counter3;
	Counter *counter4;

	void ConductCollisionCheckingsButNotHandleIt(float deltaTime);
	std::vector<GameEntity *> entities;

public:
	GameScene();
	~GameScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
