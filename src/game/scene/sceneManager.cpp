#include <iostream>
#include "sceneManager.h"

SceneManager::SceneManager()
{
	mainMenuScene = new MainMenuScene();
	levelSelectScene = new LevelSelectScene();
	gameScene = new GameScene();
	leaderboardScene = new LeaderboardScene();
	pauseMenuScene = new PausedMenuScene();
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
	mainMenuScene->Begin();
	levelSelectScene->Begin();
	gameScene->Begin();
	leaderboardScene->Begin();
	pauseMenuScene->Begin();
	currentScene = mainMenuScene;
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
	if (currentScene != levelSelectScene)
	{
		currentScene->End();
	}
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
	if (currentScene != pauseMenuScene)
	{
		currentScene->End();
	}
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