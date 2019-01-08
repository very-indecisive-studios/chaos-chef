#pragma once

#include "scene.h"
#include "game/entity/player/player.h"
#include "core/sprites/sprite.h"
#include "game/gameplay/order/orderManager.h"
#include "game/gameplay/vehicleSpawn/vehicleSpawner.h"
#include "core/text/text.h"
#include "game/entity/trashBin/trashBinArea.h"


class GameScene : public Scene
{
private:
	Player *player = nullptr;
	Sprite *map = nullptr;
	Sprite *hud = nullptr;
	Text *handText = nullptr;
	Text *ordersText = nullptr;

	OrderManager *orderManager = nullptr;
	VehicleSpawner *vehicleSpawner = nullptr;
	
	TrashBinArea *trashBinArea = nullptr;
	std::vector<GameEntity *> entities;

	const FoodMenu *currentFoodMenu;
	bool isPaused = false;
	Text *pauseText;
	Text *scoreText;

	AudioPlayer *gameMusicPlayer;

	void ConductCollisionCheckingsButNotHandleIt(float deltaTime);
public:
	GameScene(const FoodMenu *foodMenu);
	~GameScene();

	void SetFoodMenu(const FoodMenu *foodMenu);

	void Update(float deltaTime) override;
};
