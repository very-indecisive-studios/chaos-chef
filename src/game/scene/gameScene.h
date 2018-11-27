#pragma once

#include "scene.h"
#include "game/entity/player.h"
#include "game/entity/dispenser.h"
#include "game/entity/dispenserArea.h"
#include "game/entity/counter.h"
#include "game/entity/counterArea.h"
#include "game/entity/trashBin.h"
#include "game/entity/trashBinArea.h"
#include "game/entity/vehicle.h"
#include "core/sprites/sprite.h"
#include "game/order/orderManager.h"


class GameScene : public Scene
{
private:
	Player *player;
	Sprite *map;
	Sprite *hud;

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

	Vehicle *vehicle;
	OrderManager *orderManager;
	
	std::vector<GameEntity *> entities;
	void ConductCollisionCheckingsButNotHandleIt(float deltaTime);

public:
	GameScene();
	~GameScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
