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
	Scene *currentScene;

	MainMenuScene *mainMenuScene;
	LevelSelectScene *levelSelectScene;
	GameScene *gameScene;
	LeaderboardScene *leaderboardScene;
	PausedMenuScene *pauseMenuScene;

public:
	SceneManager();
	~SceneManager();

	void Initialize();

	void LoadMainMenuScene();
	void LoadSelectLevelScene();
	void LoadGameScene(const FoodMenu *foodMenu);
	void LoadPausedMenuScene();
	void LoadLeaderboardScene();

	void Update(float deltaTime);
};
