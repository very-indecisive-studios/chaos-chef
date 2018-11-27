#pragma once

#include "scene.h"
#include "game/entity/player.h"
#include "game/entity/dispenser.h"
#include "game/entity/dispenserArea.h"
#include "game/entity/counter.h"
#include "game/entity/counterArea.h"
#include "core/sprites/sprite.h"

class GameScene : public Scene
{
private:
	Player *player;
	Sprite *map;

	Dispenser *dispenser1;
	DispenserArea *dispenser1Area;
	Dispenser *dispenser2;
	DispenserArea *dispenser2Area;
	Dispenser *dispenser3;
	DispenserArea *dispenser3Area;
	Dispenser *dispenser4;
	DispenserArea *dispenser4Area;
	Dispenser *dispenser5;
	DispenserArea *dispenser5Area;

	Counter *counter;
	CounterArea *counter1Area;
	CounterArea *counter2Area;
	CounterArea *counter3Area;
	CounterArea *counter4Area;

	void ConductCollisionCheckingsButNotHandleIt(float deltaTime);
	std::vector<GameEntity *> entities;

public:
	GameScene();
	~GameScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
