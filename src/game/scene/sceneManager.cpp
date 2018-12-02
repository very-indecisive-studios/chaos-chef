#include <iostream>
#include "sceneManager.h"

SceneManager::SceneManager()
{
	mainMenuScene = new MainMenuScene();
	levelSelectScene = new LevelSelectScene();
	gameScene = new GameScene();
	leaderboardScene = new LeaderboardScene();
	pauseMenuScene = new PausedMenuScene();
	currentScene = leaderboardScene;
}

SceneManager::~SceneManager()
{ 
	delete mainMenuScene;
	delete levelSelectScene;
	delete gameScene;
	delete leaderboardScene;
	delete pauseMenuScene;
}

void SceneManager::Begin() 
{
	gameScene->Begin();
	levelSelectScene->Begin();
	gameScene->Begin();
	leaderboardScene->Begin();
	pauseMenuScene->Begin();
	LoadGameScene();
	currentScene = leaderboardScene;
}

void SceneManager::LoadMainMenuScene()
{
	if (currentScene != mainMenuScene) 
	{
		currentScene->End();
	}
	currentScene = mainMenuScene;
}

void SceneManager::LoadSelectLevelScene()
{
	currentScene->End();
	currentScene = levelSelectScene;
}

void SceneManager::LoadGameScene()
{
	if (currentScene != gameScene)
	{
		currentScene->End();
	}
	currentScene = gameScene;
}

void SceneManager::LoadPausedMenuScene()
{
	currentScene->End();
	currentScene = pauseMenuScene;
}

void SceneManager::LoadLeaderboardScene()
{
	if (currentScene != leaderboardScene)
	{
		currentScene->End();
	}
	currentScene = leaderboardScene;
}

void SceneManager::Update(float deltaTime) 
{
	currentScene->Update(deltaTime);
}