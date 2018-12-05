#include <iostream>
#include "gameScene.h"
#include "game/resources.h"
#include "game/data/gameSceneData.h"
#include "game/data/food.h"
#include "game/entity/dispenser/dispenser.h"
#include "game/entity/dispenser/dispenserArea.h"
#include "game/entity/counter/counterArea.h"
#include "game/entity/prop.h"
#include "game/entity/trashBin/trashBinArea.h"
#include "game/gameplay/vehicleSpawn/vehicleSpawner.h"

GameScene::GameScene(const FoodMenu *foodMenu) 
	: Scene(SceneType::GAME)
{
	map = Sprite::Create(GAME_SCENE_IMAGE, 0);

	orderManager = new OrderManager(foodMenu, 10);

	// Initialize player.
	player = new Player();
	player->SetPosition(GameSceneData::Map::PLAYER_SPAWN_LOCATION);

	// Initialize dispensers & its area by using the food menu.
	auto plFoodIt = foodMenu->platedFoods.begin();
	for (const auto &dispenserWAreaLocations : GameSceneData::Map::DISPENSERS_W_AREA_LOCATIONS)
	{
		Dispenser *dispenser = new Dispenser();
		dispenser->SetPosition(dispenserWAreaLocations.first);
		entities.push_back(dispenser);

		DispenserArea *dispenserArea = new DispenserArea();
		dispenserArea->SetPosition(dispenserWAreaLocations.second);
		dispenserArea->SetDispenser(dispenser);
		entities.push_back(dispenserArea);

		if (plFoodIt == foodMenu->platedFoods.end())
		{
			dispenser->SetPlatedFood(nullptr);
		}
		else
		{
			dispenser->SetPlatedFood(*plFoodIt);
			++plFoodIt;
		}
	}
	int counterNo = 0;
	// Initialize counters.
	for (const auto &counterAreaLocations : GameSceneData::Map::COUNTER_AREA)
	{
		CounterArea *counterArea = new CounterArea(counterNo, orderManager);
		counterArea->SetPosition(counterAreaLocations);
		entities.push_back(counterArea);
		counterNo++;
	}

	// Initialize props.
	for (const auto &propLocationBounds : GameSceneData::Map::PROPS_LOCATION_BOUNDS)
	{
		Prop *prop = new Prop();
		prop->SetPosition(propLocationBounds.first);
		prop->SetCollisionBounds(propLocationBounds.second);
		entities.push_back(prop);
	}

	// Initialize trash bin and its area.
	Prop *trashBin = new Prop();
	trashBin->SetPosition(GameSceneData::Map::TRASH_BIN_LOCATION_BOUNDS.first);
	trashBin->SetCollisionBounds(GameSceneData::Map::TRASH_BIN_LOCATION_BOUNDS.second);
	entities.push_back(trashBin);

	TrashBinArea *trashBinArea = new TrashBinArea();
	trashBinArea->SetPosition(GameSceneData::Map::TRASH_BIN_AREA_LOCATION_BOUNDS.first);
	trashBinArea->SetCollisionBounds(GameSceneData::Map::TRASH_BIN_AREA_LOCATION_BOUNDS.second);
	entities.push_back(trashBinArea);

	orderManager = new OrderManager(&FOOD_MENU_SS, 10);

	vehicleSpawner = new VehicleSpawner();
}

GameScene::~GameScene()
{
	delete orderManager;

	delete vehicleSpawner;

	delete map;

	delete player;

	for (GameEntity *entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

void GameScene::SetFoodMenu(const FoodMenu *foodMenu)
{
	this->foodMenu = foodMenu;
}

void GameScene::Update(float deltaTime)
{
	orderManager->Update(deltaTime);

	vehicleSpawner->Update(deltaTime);

	map->Draw(Vector2(0, 0));
	
	player->Update(deltaTime);

	for (GameEntity *entity : entities)
	{
		entity->Update(deltaTime);
	}

	ConductCollisionCheckingsButNotHandleIt(deltaTime);
}

void GameScene::ConductCollisionCheckingsButNotHandleIt(float deltaTime)
{
	for (GameEntity *entity : entities)
	{
		if (player->CollidedWith(entity))
		{
			player->HandleCollision(entity);
		}
	}

	vehicleSpawner->CheckCollisionWithVehicles(player);
}