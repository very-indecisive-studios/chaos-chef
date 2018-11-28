#include <iostream>
#include "gameScene.h"
#include "game/resources.h"
#include "game/data/food.h"
#include "game/entity/dispenser/dispenser.h"
#include "game/entity/dispenser/dispenserArea.h"

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

	// Initializing a dispenser (same for counter)
	Dispenser		*dispenser1 = new Dispenser();
	DispenserArea	*dispenser1Area = new DispenserArea();
	dispenser1->SetPosition(Vector2(0, 82));
	dispenser1->SetPlatedFood(&PFOOD_PIZZA_CHEESE); // temp
	dispenser1Area->SetDispenser(dispenser1);
	entities.push_back(dispenser1);
	entities.push_back(dispenser1Area);

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
			player->HandleCollision(deltaTime, entity);
		}
	}
}