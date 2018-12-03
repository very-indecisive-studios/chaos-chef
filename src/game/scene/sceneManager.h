#pragma once
#include "scene.h"
#include "mainMenuScene.h"
#include "levelSelectScene.h"
#include "pausedMenuScene.h"
#include "gameScene.h"
#include "leaderboardScene.h"

class SceneManager
{
private:
	Scene *currentScene = nullptr;
	Scene *pendingSceneToLoad = nullptr;

public:
	SceneManager();
	~SceneManager();

	void Initialize();

	void LoadMainMenuScene();
	void LoadSelectLevelScene();
	void LoadGameScene(const FoodMenu *foodMenu);
	void LoadPausedMenuScene();
	void LoadLeaderboardScene(bool needAddPlayer);

	void Update(float deltaTime);
};
