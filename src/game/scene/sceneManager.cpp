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

void SceneManager::LoadInstructionScene()
{
	Scene *instructionScene = new InstructionScene();

	pendingSceneToLoad = instructionScene;
}

void SceneManager::LoadPreLeaderboardScene()
{
	Scene *preLeaderboardScene = new PreLeaderboardScene();

	pendingSceneToLoad = preLeaderboardScene;
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

void SceneManager::LoadLeaderboardScene(bool needAddPlayer, int playerScore, std::string level)
{
	Scene *leaderboardScene = new LeaderboardScene(needAddPlayer, playerScore, level);

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