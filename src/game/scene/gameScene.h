#pragma once

#include "scene.h"
#include "game/entity/player/player.h"
#include "core/sprites/sprite.h"
#include "game/gameplay/order/orderManager.h"
#include "game/gameplay/vehicleSpawn/vehicleSpawner.h"


class GameScene : public Scene
{
private:
	Player *player = nullptr;
	Sprite *map = nullptr;

	OrderManager *orderManager = nullptr;
	VehicleSpawner *vehicleSpawner = nullptr;
	
	std::vector<GameEntity *> entities;

	const FoodMenu *foodMenu = &FOOD_MENU_SS;


	void ConductCollisionCheckingsButNotHandleIt(float deltaTime);
public:
	GameScene(const FoodMenu *foodMenu);
	~GameScene();

	void SetFoodMenu(const FoodMenu *foodMenu);

	void Update(float deltaTime) override;
};
