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
#include "context.h"
#include "core/text/text.h"
#include "constants.h"

GameScene::GameScene(const FoodMenu *foodMenu) 
	: Scene(SceneType::GAME)
{
	currentFoodMenu = foodMenu;
	map = Sprite::Create(GAME_SCENE_IMAGE, Layer::BACKGROUND);
	hud = Sprite::Create(GAME_SCENE_HUD_IMAGE, Layer::HUD);
	handText = Text::Create("HAND", FONT_TYPE, FONT_COLOR_BLACK, 16, 100, true, false, DT_LEFT);
	ordersText = Text::Create("ORDERS", FONT_TYPE, FONT_COLOR_BLACK, 16, 100, true, false, DT_LEFT);

	pauseText = Text::Create("PAUSED", FONT_TYPE, FONT_COLOR_WHITE, 64, 100, false, false);
	scoreText = Text::Create("", FONT_TYPE, FONT_COLOR_BLACK, 24, 100, false, false);
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

	trashBinArea = new TrashBinArea();
	trashBinArea->SetPosition(GameSceneData::Map::TRASH_BIN_AREA_LOCATION_BOUNDS.first);
	trashBinArea->SetCollisionBounds(GameSceneData::Map::TRASH_BIN_AREA_LOCATION_BOUNDS.second);
	entities.push_back(trashBinArea);

	vehicleSpawner = new VehicleSpawner();

	gameMusicPlayer = AudioPlayer::Create(GAME_MUSIC_AUDIO);
	gameMusicPlayer->SetVolume(0.5f);
	gameMusicPlayer->Play();
}

GameScene::~GameScene()
{
	delete orderManager;

	delete vehicleSpawner;

	delete map;
	delete hud;
	delete ordersText;
	delete handText;
	delete scoreText;

	delete player;

	for (GameEntity *entity : entities)
	{
		delete entity;
	}
	entities.clear();

	delete gameMusicPlayer;

}

void GameScene::SetFoodMenu(const FoodMenu *foodMenu)
{
	this->currentFoodMenu = foodMenu;
}

void GameScene::Update(float deltaTime)
{
	int playerScore = orderManager->GetScore() - trashBinArea->GetTrashScore();

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_ESCAPE)) 
	{
		Context::Get()->GetInputManager()->ClearAll();
		isPaused = !isPaused;
		
	}
	if (isPaused) 
	{
		pauseText->Draw(Vector2(0, GAME_HEIGHT / 2 - 64/2));
		return;
	}
	if (orderManager->HasMissedOrder())
	{
		Context::Get()->GetInputManager()->ClearAll();
		Context::Get()->GetSceneManager()->LoadGameOverScene(1, true, playerScore, currentFoodMenu->name);
	}
	if (player->isDead())
	{
		Context::Get()->GetInputManager()->ClearAll();
		Context::Get()->GetSceneManager()->LoadGameOverScene(2, true, playerScore, currentFoodMenu->name);
	}
	orderManager->Update(deltaTime);

	vehicleSpawner->Update(deltaTime);

	map->Draw(Vector2(0, 0));
	hud->Draw(Vector2(0, 0));
	handText->Draw(GameSceneData::Hud::Top::HAND_TEXT_LOCATION);
	ordersText->Draw(GameSceneData::Hud::Bottom::ORDER_TEXT_LOCATION);

	scoreText->SetText("SCORE: " + std::to_string(playerScore));
	scoreText->Draw(Vector2(440, 22.25));
	
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