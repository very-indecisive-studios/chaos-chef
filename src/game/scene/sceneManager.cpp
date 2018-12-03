#include <iostream>
#include "sceneManager.h"

SceneManager::SceneManager()
{ }

SceneManager::~SceneManager()
{ 
	delete currentScene;
}

void SceneManager::Initialize()
{
	Scene *mainMenuScene = new MainMenuScene();

	currentScene = mainMenuScene;
}

void SceneManager::LoadMainMenuScene()
{
	Scene *mainMenuScene = new MainMenuScene();

	pendingSceneToLoad = mainMenuScene;
}

void SceneManager::LoadSelectLevelScene()
{
	Scene *levelSelectScene = new LevelSelectScene();

	pendingSceneToLoad = levelSelectScene;
}

void SceneManager::LoadGameScene(const FoodMenu *foodMenu)
{
	Scene *gameScene = new GameScene(foodMenu);

	pendingSceneToLoad = gameScene;
}

void SceneManager::LoadPausedMenuScene()
{
	Scene *pausedMenuScene = new PausedMenuScene();

	pendingSceneToLoad = pausedMenuScene;
}

void SceneManager::LoadLeaderboardScene()
{
	Scene *leaderboardScene = new LeaderboardScene();

	pendingSceneToLoad = leaderboardScene;
}

void SceneManager::Update(float deltaTime) 
{
	if (pendingSceneToLoad != nullptr)
	{
		delete currentScene;

		currentScene = pendingSceneToLoad;
		
		pendingSceneToLoad = nullptr;
	}
	else
	{
		currentScene->Update(deltaTime);
	}
}