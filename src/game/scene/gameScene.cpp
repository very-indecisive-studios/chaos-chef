#include <iostream>
#include "gameScene.h"
#include "game/resources.h"
#include <iostream>
#include "game/data/food.h"

GameScene::GameScene()
{ }

GameScene::~GameScene()
{
	End();
}

void GameScene::Begin()
{
	map = Sprite::Create(MAP_IMAGE, 0);

	player	= new Player();

	// Dispensers
	dispenser1 = new Dispenser();
	dispenser1Area = new DispenserArea();
	dispenser2 = new Dispenser();
	dispenser2Area = new DispenserArea();
	dispenser3 = new Dispenser();
	dispenser3Area = new DispenserArea();
	dispenser4 = new Dispenser();
	dispenser4Area = new DispenserArea();
	dispenser5 = new Dispenser();
	dispenser5Area = new DispenserArea();

	CollisionBounds dispenserCB;
	dispenserCB.topLeft	 = Vector2(0, 0);
	dispenserCB.bottomRight = Vector2(32, 32);

	dispenser1->SetCollisionBounds(dispenserCB);
	dispenser1->SetPosition(Vector2(0, 82));
	dispenser1->SetIngredient(&PFOOD_SS_RICE); // temp
	entities.push_back(dispenser1);

	dispenser2->SetCollisionBounds(dispenserCB);
	dispenser2->SetPosition(Vector2(0, 130));
	dispenser2->SetIngredient(&PFOOD_SS_PRAWN); // temp
	entities.push_back(dispenser2);

	dispenser3->SetCollisionBounds(dispenserCB);
	dispenser3->SetPosition(Vector2(0, 177));
	dispenser3->SetIngredient(&PFOOD_SS_FISH); // temp
	entities.push_back(dispenser3);

	dispenser4->SetCollisionBounds(dispenserCB);
	dispenser4->SetPosition(Vector2(0, 225));
	entities.push_back(dispenser4);
	
	dispenser5->SetCollisionBounds(dispenserCB);
	dispenser5->SetPosition(Vector2(0, 274));
	entities.push_back(dispenser5);

	CollisionBounds dispenserAreaCB;
	dispenserAreaCB.topLeft = Vector2(0, 0);
	dispenserAreaCB.bottomRight = Vector2(32, 32);

	dispenser1Area->SetCollisionBounds(dispenserCB);
	dispenser1Area->SetPosition(Vector2(32, 82));
	dispenser1Area->SetDispenser(dispenser1);
	entities.push_back(dispenser1Area);

	dispenser2Area->SetCollisionBounds(dispenserCB);
	dispenser2Area->SetPosition(Vector2(32, 130));
	dispenser2Area->SetDispenser(dispenser2);
	entities.push_back(dispenser2Area);

	dispenser3Area->SetCollisionBounds(dispenserCB);
	dispenser3Area->SetPosition(Vector2(32, 177));
	dispenser3Area->SetDispenser(dispenser3);
	entities.push_back(dispenser3Area);

	dispenser4Area->SetCollisionBounds(dispenserCB);
	dispenser4Area->SetPosition(Vector2(32, 225));
	dispenser4Area->SetDispenser(dispenser4);
	entities.push_back(dispenser4Area);

	dispenser5Area->SetCollisionBounds(dispenserCB);
	dispenser5Area->SetPosition(Vector2(32, 274));
	dispenser5Area->SetDispenser(dispenser5);
	entities.push_back(dispenser5Area);

	// Counters
	counter = new Counter();
	counter1Area = new CounterArea();
	counter2Area = new CounterArea();
	counter3Area = new CounterArea();
	counter4Area = new CounterArea();

	CollisionBounds counterCB;
	counterCB.topLeft = Vector2(0, 0);
	counterCB.bottomRight = Vector2(15, MAP_HEIGHT);

	counter->SetCollisionBounds(counterCB);
	counter->SetPosition(Vector2(550, 0));
	entities.push_back(counter);

	CollisionBounds counterAreaCB;
	counterAreaCB.topLeft = Vector2(0, 0);
	counterAreaCB.bottomRight = Vector2(16, 16);

	counter1Area->SetCollisionBounds(counterAreaCB);
	counter1Area->SetPosition(Vector2(540, 65));
	entities.push_back(counter1Area);

	counter2Area->SetCollisionBounds(counterAreaCB);
	counter2Area->SetPosition(Vector2(540, 125));
	entities.push_back(counter2Area);

	counter3Area->SetCollisionBounds(counterAreaCB);
	counter3Area->SetPosition(Vector2(540, 185));
	entities.push_back(counter3Area);

	counter4Area->SetCollisionBounds(counterAreaCB);
	counter4Area->SetPosition(Vector2(540,245));
	entities.push_back(counter4Area);

	// Vehicles
	vehicle = new Vehicle();

	CollisionBounds vehicleCB;
	vehicleCB.topLeft = Vector2(0, 0);
	vehicleCB.bottomRight = Vector2(32, 64);

	vehicle->SetCollisionBounds(vehicleCB);
	vehicle->SetPosition(Vector2(176, 0));
	entities.push_back(vehicle);

	orderManager = new OrderManager(&FOOD_MENU_SS, 10);

	map		= Sprite::Create(MAP_IMAGE, 0);
}

void GameScene::Update(float deltaTime)
{
	orderManager->Update(deltaTime);

	//std::cout << std::endl;
	for (Order *order : orderManager->GetOrders())
	{	
		//std::cout << order->meal->name << std::endl;
		//std::cout << order->timeRemainingSeconds << std::endl << std::endl;
	}
	//std::cout << "has order missed? " << orderManager->HasMissedOrder() << std::endl;
	//std::cout << std::endl;

	map->Draw(Vector2(0, 0));
	vehicle->Update(deltaTime);
	player->Update(deltaTime);

	ConductCollisionCheckingsButNotHandleIt(deltaTime);
}

void GameScene::End()
{
	for (GameEntity *entity : entities)
	{
		delete entity;
	}
	entities.clear();

	delete player;
	delete map;
	delete orderManager;
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