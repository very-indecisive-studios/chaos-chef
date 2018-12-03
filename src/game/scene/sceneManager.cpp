#include <iostream>
#include "sceneManager.h"

SceneManager::SceneManager()
{
	mainMenuScene		= new MainMenuScene();
	levelSelectScene	= new LevelSelectScene();
	gameScene			= new GameScene();
	leaderboardScene	= new LeaderboardScene();
	pauseMenuScene		= new PausedMenuScene();
}

SceneManager::~SceneManager()
{ 
	delete mainMenuScene;
	delete levelSelectScene;
	delete gameScene;
	delete leaderboardScene;
	delete pauseMenuScene;
}

void SceneManager::Initialize()
{
	currentScene = mainMenuScene;
	mainMenuScene->Begin();
}

void SceneManager::LoadMainMenuScene()
{
	currentScene->End();

	currentScene = mainMenuScene;
	currentScene->Begin();
}

void SceneManager::LoadSelectLevelScene()
{
	currentScene->End();

	currentScene = levelSelectScene;
	currentScene->Begin();
}

void SceneManager::LoadGameScene(const FoodMenu *foodMenu)
{
	currentScene->End();

	gameScene->SetFoodMenu(foodMenu);
	gameScene->Begin();
	
	currentScene = gameScene;
}

void SceneManager::LoadPausedMenuScene()
{
	currentScene->End();

	currentScene = pauseMenuScene;
	currentScene->Begin();
}

void SceneManager::LoadLeaderboardScene()
{
	currentScene->End();

	currentScene = leaderboardScene;
	currentScene->Begin();
}

void SceneManager::Update(float deltaTime) 
{
	currentScene->Update(deltaTime);
}