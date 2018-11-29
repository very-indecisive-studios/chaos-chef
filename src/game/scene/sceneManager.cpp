#include <iostream>
#include "sceneManager.h"
#include "game/scene/gameScene.h"
#include "game/scene/leaderboardScene.h"

SceneManager::SceneManager()
{
	//currentScene = ;
}

SceneManager::~SceneManager(){ }

void SceneManager::Update(float deltaTime) 
{
	currentScene->Begin();
}