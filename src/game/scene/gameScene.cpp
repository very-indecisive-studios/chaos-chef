#include "gameScene.h"
#include "game/resources.h"

GameScene::GameScene()
{ }

GameScene::~GameScene()
{
	End();
}

void GameScene::Begin()
{
	player	= new Player();
	map		= Sprite::Create(MAP_IMAGE, 0);
}

void GameScene::Update(float deltaTime)
{
	map->Draw(Vector2(0, 0));
	player->Update(deltaTime);

	CheckCollisions();
}

void GameScene::End()
{
	if (player) delete player;
	if (map) delete map;
}

void GameScene::CheckCollisions()
{

}
