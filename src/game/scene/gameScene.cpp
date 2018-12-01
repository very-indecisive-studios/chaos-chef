#include <iostream>
#include "gameScene.h"
#include "game/resources.h"
#include "game/data/food.h"
#include "game/entity/dispenser/dispenser.h"
#include "game/entity/dispenser/dispenserArea.h"
#include "game/entity/prop.h"
#include "game/entity/trashBin/trashBinArea.h"

GameScene::GameScene() : Scene(SceneType::GAME){ }

GameScene::~GameScene()
{
	End();
}

void GameScene::Begin()
{
	map = Sprite::Create(MAP_IMAGE, 0);
	hud = Sprite::Create(HUD_IMAGE, 0);

	player	= new Player();

	// Initialize dispensers & its area.
	for (const auto &dispenserWAreaLocations : Map::DISPENSERS_W_AREA_LOCATIONS)
	{
		Dispenser *dispenser = new Dispenser();
		dispenser->SetPosition(dispenserWAreaLocations.first);
		dispenser->SetPlatedFood(&PFOOD_FB_CHICKEN);
		entities.push_back(dispenser);
		
		DispenserArea *dispenserArea = new DispenserArea();
		dispenserArea->SetPosition(dispenserWAreaLocations.second);
		dispenserArea->SetDispenser(dispenser);
		entities.push_back(dispenserArea);
	}

	// Initialize props.
	for (const auto &propLocationBounds : Map::PROPS_LOCATION_BOUNDS)
	{
		Prop *prop = new Prop();
		prop->SetPosition(propLocationBounds.first);
		prop->SetCollisionBounds(propLocationBounds.second);
		entities.push_back(prop);
	}

	// Initialize trash bin and its area.
	Prop *trashBin = new Prop();
	trashBin->SetPosition(Map::TRASH_BIN_LOCATION_BOUNDS.first);
	trashBin->SetCollisionBounds(Map::TRASH_BIN_LOCATION_BOUNDS.second);
	entities.push_back(trashBin);

	TrashBinArea *trashBinArea = new TrashBinArea();
	trashBinArea->SetPosition(Map::TRASH_BIN_AREA_LOCATION_BOUNDS.first);
	trashBinArea->SetCollisionBounds(Map::TRASH_BIN_AREA_LOCATION_BOUNDS.second);
	entities.push_back(trashBinArea);

	orderManager = new OrderManager(&FOOD_MENU_SS, 10);
}

void GameScene::Update(float deltaTime)
{
	orderManager->Update(deltaTime);

	map->Draw(Vector2(0, 0));
	hud->Draw(Vector2(0, MAP_HEIGHT));
	
	player->Update(deltaTime);

	for (GameEntity *entity : entities)
	{
		entity->Update(deltaTime);
	}

	ConductCollisionCheckingsButNotHandleIt(deltaTime);
}

void GameScene::End()
{
	delete orderManager;

	delete map;
	delete hud;

	delete player;

	for (GameEntity *entity : entities)
	{
		delete entity;
	}
	entities.clear();
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
}