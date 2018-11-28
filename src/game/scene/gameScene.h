#pragma once

#include "scene.h"
#include "game/entity/player/player.h"
#include "core/sprites/sprite.h"
#include "game/gameplay/order/orderManager.h"


class GameScene : public Scene
{
private:
	Player *player;
	Sprite *map;
	Sprite *hud;

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
