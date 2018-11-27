#include "gameScene.h"
#include "game/resources.h"
#include <iostream>
GameScene::GameScene(){ }

GameScene::~GameScene()
{
	End();
}

void GameScene::Begin()
{
	map = Sprite::Create(MAP_IMAGE, 0);

	player	= new Player();
	dispenser1 = new Dispenser();
	dispenser2 = new Dispenser();
	dispenser3 = new Dispenser();
	dispenser4 = new Dispenser();
	dispenser5 = new Dispenser();
	counter1 = new Counter();
	counter2 = new Counter();
	counter3 = new Counter();
	counter4 = new Counter();

	CollisionBounds dispenserCollisionBounds;
	dispenserCollisionBounds.topLeft	 = Vector2(0, 0);
	dispenserCollisionBounds.bottomRight = Vector2(32, 32);

	CollisionBounds counterCollisionBounds;
	counterCollisionBounds.topLeft = Vector2(0, 0);
	counterCollisionBounds.bottomRight = Vector2(32, 32);

	dispenser1->SetCollisionBounds(dispenserCollisionBounds);
	dispenser1->SetPosition(Vector2(0, 82));
	entities.push_back(dispenser1);

	dispenser2->SetCollisionBounds(dispenserCollisionBounds);
	dispenser2->SetPosition(Vector2(0, 130));
	entities.push_back(dispenser2);

	dispenser3->SetCollisionBounds(dispenserCollisionBounds);
	dispenser3->SetPosition(Vector2(0, 177));
	entities.push_back(dispenser3);

	dispenser4->SetCollisionBounds(dispenserCollisionBounds);
	dispenser4->SetPosition(Vector2(0, 225));
	entities.push_back(dispenser4);
	
	dispenser5->SetCollisionBounds(dispenserCollisionBounds);
	dispenser5->SetPosition(Vector2(0, 274));
	entities.push_back(dispenser5);

	counter1->SetCollisionBounds(counterCollisionBounds);
	counter1->SetPosition(Vector2(512, 50));
	entities.push_back(counter1);

	counter2->SetCollisionBounds(counterCollisionBounds);
	counter2->SetPosition(Vector2(512, 115));
	entities.push_back(counter2);

	counter3->SetCollisionBounds(counterCollisionBounds);
	counter3->SetPosition(Vector2(512, 180));
	entities.push_back(counter3);

	counter4->SetCollisionBounds(counterCollisionBounds);
	counter4->SetPosition(Vector2(512, 245));
	entities.push_back(counter4);
}

void GameScene::Update(float deltaTime)
{
	map->Draw(Vector2(0, 0));
	player->Update(deltaTime);

	ConductCollisionCheckingsButNotHandleIt(deltaTime);
}

void GameScene::End()
{
	if (player) delete player;
	if (map) delete map;
	if (dispenser1) delete dispenser1;
	if (dispenser2) delete dispenser2;
	if (dispenser3) delete dispenser3;
	if (dispenser4) delete dispenser4;
	if (dispenser5) delete dispenser5;
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